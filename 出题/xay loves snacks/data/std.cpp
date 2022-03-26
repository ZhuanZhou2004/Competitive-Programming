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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int N = 10000005;
const ll inf = 1e18;

int a[N], n, m, seed, mod;

ll dis[30000005];
#define pli pair<ll, int>
priority_queue<pli, vector<pli>, greater<pli>> pq;
void dijkstra() {
  for (int i = 0; i < mod; i++) dis[i] = inf;
  pq.push({0, 0}), dis[0] = 0;
  while (!pq.empty()) {
    pli it = pq.top(); pq.pop();
    int u = it.sec;
    if (dis[u] != it.fir) continue;
    for (int i = 1; i <= n; i++) {
      int to = (u + a[i]) % mod;
      if (dis[to] > dis[u] + a[i]) {
        dis[to] = dis[u] + a[i];
        pq.push({dis[to], to});
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &seed);
  mod = m;
  mt19937 rng(seed);
  auto get = [&]() {
    uniform_int_distribution<int> qwq(2, m);
    return qwq(rng);
  };
  for (int i = 1; i <= n; i++) {
    a[i] = get();
//    printf("%d ", a[i]);
    mod = min(mod, a[i]);
  }
//  printf("mod = %d\n", mod);
//  printf("%d\n", m / (n + 1));
  dijkstra();
  ll ans = -1;
  for (int i = 0; i < mod; i++) {
    ckmax(ans, dis[i] - mod);
  }
  print(ans, '\n');
}

// 50 100000000 114514
