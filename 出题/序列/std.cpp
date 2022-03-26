// Author: wlzhouzhuan
#pragma GCC optimize("Ofast") 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int mod = 1e9 + 9;
const int N = 1e6 + 5;

int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1; 
  }
  return res;
}
int fac[N], ifac[N], pw1[N], pw2[N], n;
void init(int n) {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  for (int i = n - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
  return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
void solve() {
  n = read();
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw1[i] = 1ll * pw1[i - 1] * n % mod;
    pw2[i] = 1ll * pw2[i - 1] * (mod + 1 - n) % mod;
  }
  int ans = 0;
  for (int k = 1; k <= n; k++) {
    for (int i = 0; i <= n / k; i++) {
      int t = n - i * k + i - 1;
      if (!i) {
        add(ans, 1ll * pw1[n - i * k] * pw2[i] % mod * C(t, i) % mod);
        continue;
      }
      add(ans, 1ll * pw1[n - i * k] * pw2[i] % mod * C(t, i) % mod);
      sub(ans, 1ll * pw1[n - i * k + 1] * pw2[i - 1] % mod * C(t, i - 1) % mod);
    }
  }
  ans = (1ll * n * qpow(n, n) % mod - ans + mod) % mod;
  print(ans, '\n');
}
int main() {
//  freopen("seq24.in", "r", stdin);
//  freopen("seq24.out", "w", stdout);
  init(1e6);
  int T = read();
  while (T--) solve();
  return 0;
}
