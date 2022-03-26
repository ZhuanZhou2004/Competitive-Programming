// Author: wlzhouzhuan 
#include <bits/stdc++.h>
#include "dsu.h"
using namespace std;

#define SZ(x) (int(x.size()))
#define pb push_back
#define fir first
#define sec second
#define lowbit(x) (x & (-x))

struct node {
  int op, id;
};
vector<node> buf;
vector<int> tmp[2];

int r, n, m, limit, cnt;

void init(int nn, int mm, int limits) {
  n = nn, m = mm, limit = limits, r = 1, cnt = 0;
  buf.clear(), tmp[0].clear(), tmp[1].clear();
}
int solve(int l) {
  while (r <= m && check(r)) {
    merge(r);
    buf.pb({1, r}), r++;
  }
  if (!cnt) {
    for (auto v: buf) undo();
    reverse(buf.begin(), buf.end());
    for (auto &v: buf) v.op = 0, merge(v.id);
    cnt = SZ(buf);
  }
  if (buf.back().op == 1) {
    while (buf.back().op == 1) {
      node it = buf.back(); buf.pop_back();
      tmp[1].pb(it.id), undo();
    }
    int del = lowbit(cnt);
    while (del--) {
      node it = buf.back(); buf.pop_back();
      tmp[0].pb(it.id), undo();
    }
    while (!tmp[1].empty()) {
      int v = tmp[1].back(); tmp[1].pop_back();
      buf.pb({1, v});
      merge(v);
    }
    while (!tmp[0].empty()) {
      int v = tmp[0].back(); tmp[0].pop_back();
      buf.pb({0, v});
      merge(v);
    }
  }
  buf.pop_back(), undo(), cnt--;
  return r - 1;
}
