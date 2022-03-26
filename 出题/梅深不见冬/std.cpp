// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const ll mod = 998244353;
const int N = 10000002;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

bitset <N> vis;
int pr[N >> 1], l;
ll phi[N];
ll n, k, L;
inline void pre(int n) {
  //cerr << "debug: " << n << '\n';
  phi[1] = 1;
  for (rint i = 2; i <= n; i++) {
    if (!vis[i]) pr[l++] = i, phi[i] = i - 1;
    for (rint j = 0; j < l && pr[j] * i <= n; j++) {
      int v = pr[j]; vis[v * i] = 1;
      if (i % v == 0) {
        phi[i * v] = phi[i] * v;
        break;
      }
      phi[i * v] = phi[i] * (v - 1);
    }
  }
  for (rint i = 1; i <= n; i++) phi[i] = (phi[i] + phi[i - 1]) % mod;
}

unordered_map <ll, ll> Map;
ll S(ll n) {
  if (n <= L) return phi[n];
  if (Map[n]) return Map[n];
  ll res = n * (n + 1) / 2 % mod;
  for (ll i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    res = (res + mod - (j - i + 1) * S(n / i) % mod) % mod;
  }
  if (res < 0) res += mod;
  return Map[n] = res;
}
ll solve(ll n, ll k) {
  ll lst = 0, now = 0, ans = 0; k %= (mod - 1);
  for (ll i = 1, j; i <= n; i = j + 1) {
    j = n / (n / i);
    now = (S(j) % mod + mod) % mod;
    //printf("lst = %lld, now = %lld\n", lst, now);
    //printf(">> %lld %lld\n", i, j);
    ans = (ans + qpow(n / i, k) * (now - lst + mod) % mod) % mod;
    lst = now;
  }
  return ans;
}

int main() {
  scanf("%lld%lld", &n, &k);
  //L = n; pre(L);
  L = pow(n, 2.0 / 3); pre(L);
  printf("%lld\n", solve(n, k));
  return 0;
}

/*
[1-3] 2
[4-5] 3
[6-8] 3
[9-12] 3
[13-20] 4
[21-25] 4
[26-29] 6
*/
