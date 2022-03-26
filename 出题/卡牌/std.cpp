// Author: wlzhouzhuan
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
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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

#define poly vector<int>
#define SZ(a) int(a.size())
 
const int mod = 998244353;
const int G = 3, Gi = 332748118;
int add(int x, int y) {
  if ((x += y) >= mod) x -= mod;
  return x;
}
int sub(int x, int y) {
  if ((x -= y) < 0) x += mod;
  return x; 
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace Poly {
vector<int> Rev, W;
int lim, L;
void getR(int len) {
  lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  Rev.resize(lim), W.resize(lim), W[0] = 1;
  for (int i = 0; i < lim; i++) Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << L - 1);
}
void wf(poly &a) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) a[i] = 1ll * (i + 1) * a[i + 1] % mod;
  a[n - 1] = 0;
}
void jf(poly &a) {
  int n = a.size();
  for (int i = n - 1; i >= 1; i--) a[i] = 1ll * a[i - 1] * qpow(i) % mod;
  a[0] = 0;
}
void NTT(poly &a, int opt) {
  for (int i = 0; i < lim; i++) if (i < Rev[i]) swap(a[i], a[Rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int k = 1; k < mid; k++) W[k] = 1ll * W[k - 1] * Wn % mod;
    for (int j = 0; j < lim; j += mid << 1) {
      for (int k = 0; k < mid; k++) {
        int x = a[j + k], y = 1ll * W[k] * a[j + k + mid] % mod;
        a[j + k] = add(x, y);
        a[j + k + mid] = sub(x, y);
      }
    }
  }
  if (opt == -1) {
    int linv = qpow(lim);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
  }
}
poly operator * (poly a, poly b) {
  int len = a.size() + b.size() - 1;
  if (len <= 200) {
    poly c(len);
    for (int i = 0; i < SZ(a); i++) {
      for (int j = 0; j < SZ(b); j++) {
        c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % mod;
      } 
    }
    return c;
  }
  getR(len);
  a.resize(lim), b.resize(lim);
  NTT(a, 1), NTT(b, 1);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  NTT(a, -1);
  a.resize(len);
  return a;
}
poly Inv(poly a) {
  if (SZ(a) == 1) return vector<int> (1, qpow(a[0]));
  int len = a.size();
  poly ta = a; ta.resize((len + 1) / 2);
  poly tb = Inv(ta);
  getR(2 * len), a.resize(lim), tb.resize(lim);
  NTT(a, 1), NTT(tb, 1);
  for (int i = 0; i < lim; i++) tb[i] = 1ll * tb[i] * (mod + 2 - 1ll * a[i] * tb[i] % mod) % mod;
  NTT(tb, -1);
  tb.resize(len);
  return tb;
}
poly Ln(poly a) {
  poly ta = a; wf(ta);
  int len = a.size();
  a = ta * Inv(a), jf(a);
  a.resize(len);
  return a;
}
poly Exp(poly a) {
  if (SZ(a) == 1) return {1};
  int len = a.size();
  poly ta = a; ta.resize((len + 1) / 2);
  poly tb = Exp(ta); tb.resize(len);
  poly Lnb = Ln(tb);
  for (int i = 0; i < len; i++) Lnb[i] = (a[i] - Lnb[i] + mod) % mod;
  Lnb[0] = (Lnb[0] + 1) % mod;
  tb = tb * Lnb, tb.resize(len);
  return tb;
}
}
using namespace Poly;

int inv[500005];
void init(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  }
}

int mul[50000005];
int len;
int a[1005], cnt[505], b[105], n, m, S;

int main() {
  freopen("card6.in", "r", stdin);
  //freopen("3.out", "w", stdout);
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read(), cnt[a[i]]++, S += a[i];
  for (int i = 1; i <= m; i++) b[i] = read() % mod;
  init(S);
  poly f(S + 1);
  for (int i = 1; i <= 500; i++) {
    if (!cnt[i]) continue;
    for (int j = i; j <= S; j += i) {
      f[j] = (f[j] + mod - 1ll * cnt[i] * inv[j / i] % mod) % mod;
    }
  }
  
  cerr << "S = " << S << '\n';
//  for (int i = 0; i <= S; i++) printf("%d ", f[i]);
//  puts("");
  
  f = Exp(f);
  
  for (int i = 0; i <= S; i++) f[i] = (mod - f[i]) % mod;
  
  //f.resize(S + 1), f[0] = 1, f[1] = 1, f[2] = 1, f[3] = mod - 1;
  //f = Ln(f);
  
//  f = Ln(f);
  
//  for (int i = 0; i <= S; i++) printf("%d ", f[i]);
//  puts("");
  
  mul[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= S; j++) {
      mul[++len] = (b[i] + j) % mod;
    }
  }
  for (int i = 1; i <= len; i++) mul[i] = 1ll * mul[i] * mul[i - 1] % mod;
  int Inv = qpow(mul[len]), ans = 0;
  for (int i = m; i >= 1; i--) {
    for (int j = S; j >= 1; j--) {
      int t = 1ll * Inv * mul[--len] % mod;
      Inv = 1ll * Inv * ((b[i] + j) % mod) % mod;
      assert((b[i] + j) % mod != 0);
//      printf("i = %d, j = %d, t = %d\n", i, j, t);
      ans = (ans + 1ll * f[j] * b[i] % mod * t) % mod;
    }
  }
  printf("%d\n", (ans + n) % mod);
  return 0;
}
