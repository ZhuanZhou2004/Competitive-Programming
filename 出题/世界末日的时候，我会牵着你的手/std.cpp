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


char buf[1<<21],*p1=buf,*p2=buf;
int getc(){
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
int read() {
  int ret = 0,f = 0;
  char ch = getc();
  while (!isdigit (ch)) {
    if (ch == '-') f = 1;
    ch = getc();
  }
  while (isdigit (ch)) {
    ret = ret * 10 + ch - 48;
    ch = getc();
  }
  return f?-ret:ret;
}

/*
inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
*/
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 50001;
int n, q;

vector <int> adj[N];
void add(int u, int v) { adj[u].pb(v); }

int dfn[N], id[N], dtot;
int dep[N], Edfn[N], f[N << 1][17], tot;
void dfs(int u, int fa) {
  dfn[u] = ++dtot, id[dtot] = u;
  f[++tot][0] = u, Edfn[u] = tot, dep[u] = dep[fa] + 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    f[++tot][0] = u;
  }
}
int lg[N << 1];
void pre() {
  lg[1] = 0;
  for (rint i = 2; i <= tot; i++) lg[i] = lg[i >> 1] + 1;
  for (rint j = 1; j <= 16; j++) {
    for (rint i = 1; i + (1 << j) - 1 <= tot; i++) {
      if (dep[f[i][j - 1]] < dep[f[i + (1 << j - 1)][j - 1]]) {
        f[i][j] = f[i][j - 1];
      } else {
        f[i][j] = f[i + (1 << j - 1)][j - 1];
      }
    }
  }
}
int lca(int u, int v) {
  int l = Edfn[u], r = Edfn[v];
  if (l > r) swap(l, r);
  int len = lg[r - l + 1];
  if (dep[f[l][len]] < dep[f[r - (1 << len) + 1][len]]) {
    return f[l][len];
  } else {
    return f[r - (1 << len) + 1][len];
  }
}
int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

int be[N], block;
struct Query {
  int l, r, id;
  friend bool operator < (const Query &a, const Query &b) {
    if (be[a.l] != be[b.l]) return a.l < b.l;
    else if (be[a.l] & 1) return a.r > b.r;
    else return a.r < b.r;
  }
} qry[N];
int ans[N];

set <int> S;
int res = 0;
void Add(int x) {
  //printf("Add %d dfn = %d\n", x, dfn[x]);
  if (S.empty()) { S.insert(dfn[x]); return ; }
  set <int> :: iterator itl = S.lower_bound(dfn[x]);
  if (itl == S.begin()) itl = S.end();
  itl--;
  set <int> :: iterator itr = S.upper_bound(dfn[x]);
  if (itr == S.end()) itr = S.begin();
  //printf("in set: "); for (auto v: S) cout << v << ' '; cout << '\n';
  int Left = id[*itl], Right = id[*itr];
  //printf(" >>> %d %d\n", Left, Right);
  res -= dist(Left, Right);
  res += dist(Left, x) + dist(x, Right);
  S.insert(dfn[x]);
  //printf("now res = %d\n", res);
}
void Del(int x) {
  //printf("Delete %d dfn = %d\n", x, dfn[x]);
  if (S.size() <= 1) { S.erase(dfn[x]); return ; }
  set <int> :: iterator itl = S.lower_bound(dfn[x]);
  if (itl == S.begin()) itl = S.end();
  itl--;
  set <int> :: iterator itr = S.upper_bound(dfn[x]);
  if (itr == S.end()) itr = S.begin();
  int Left = id[*itl], Right = id[*itr];
  res -= dist(Left, x) + dist(x, Right);
  res += dist(Left, Right);
  S.erase(dfn[x]);
  //printf("now res = %d\n", res);
}

int main() {
  n = read(), q = read(); block = sqrt(n);
  for (rint i = 1; i <= n; i++) be[i] = i / block + 1;
  for (rint i = 1; i < n; i++) {
    int u = read(), v = read();
    add(u, v), add(v, u);
  }
  dfs(1, 0); pre();
  for (rint i = 1; i <= q; i++) {
    qry[i].l = read(), qry[i].r = read(), qry[i].id = i;
  }
  sort(qry + 1, qry + q + 1);
  
  //for (rint i = 1; i <= q; i++) {
  //  printf("%d %d\n", qry[i].l, qry[i].r);
  //}
  //for (rint i = 1; i <= n; i++) {
  //  printf("dfn[%d] = %d\n", i, dfn[i]);
  //}
  
  int l = 1, r = 0;
  for (rint i = 1; i <= q; i++) {
    while (r < qry[i].r) r++, Add(r);
    while (l > qry[i].l) l--, Add(l);
    while (r > qry[i].r) Del(r), r--;
    while (l < qry[i].l) Del(l), l++;
    ans[qry[i].id] = res / 2;
  }
  for (rint i = 1; i <= q; i++) print(ans[i]), putchar('\n'); 
  return 0;
}

