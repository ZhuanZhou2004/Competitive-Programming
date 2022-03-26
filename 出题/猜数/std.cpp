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

const int S = 4005;
const int N = 200005;
const ll inf = 1e18;
ll g[S + 1][S + 1];
ll f[N], ans;

int deq[N], h, t;
int ind[N], n;

ll dp(int l, int r) {
  if (l >= r) return 0;
  else return g[ind[r]][r - l];
}
int main() {
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) ind[i] = i % S + 1;
  for (int i = 2; i <= n; i++) {
    f[i] = inf;
    mset(g[ind[i]], 0x3f);
    // k0 表示决策点 
    int to = max(i - S + 1, 1), k0 = i;
    h = 1, t = 0;
    for (int j = i - 1; j >= to; j--) {
      while (k0 - 2 >= j && dp(j, k0 - 2) > dp(k0, i)) k0--;
      while (h <= t && deq[h] >= k0) h++;
      while (h <= t && dp(j + 1, i) + j <= dp(deq[t] + 1, i) + deq[t]) t--;
      deq[++t] = j;
      g[ind[i]][i - j] = min(dp(deq[h] + 1, i) + deq[h], dp(j, k0 - 1) + k0);
    }
    for (int k = i; k >= to; k--) {
      f[i] = min(f[i], max(f[k - 1], dp(k + 1, i)) + k);
    }
    ans += f[i];
//    printf("%lld\n", f[i]);
//    printf("f[%d] = %lld\n", i, f[i]);
  }
  printf("%lld\n", ans);
  return 0; 
}
