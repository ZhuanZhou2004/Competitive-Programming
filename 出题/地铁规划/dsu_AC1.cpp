// Author: wlzhouzhuan 
#include <bits/stdc++.h>
#include "dsu.h"
using namespace std;

#define SZ(x) (int(x.size()))
#define pb push_back
#define fir first
#define sec second

struct node {
  int op, id;
};
vector<node> buf;
vector<int> tmp[2];

int r, n, m, limit;

void init(int nn, int mm, int limits) {
  n = nn, m = mm, limit = limits, r = 1;
  buf.clear(), tmp[0].clear(), tmp[1].clear();
}
int solve(int l) {
  while (r <= m && check(r)) {
    merge(r);
    buf.pb({1, r}), r++;
  }
  if (buf.back().op == 1) {
    while (!buf.empty()) {
      node it = buf.back(); buf.pop_back();
      tmp[it.op].pb(it.id), undo();
      if (SZ(tmp[0]) == SZ(tmp[1])) break;
    }
    if (SZ(tmp[0]) != SZ(tmp[1])) {
      for (auto v: tmp[1]) {
        buf.pb({0, v});
        merge(v);
      }
      tmp[1].clear();
      while (!tmp[0].empty()) {
        int v = tmp[0].back(); tmp[0].pop_back();
        buf.pb({0, v});
        merge(v);
      }
    } else {
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
  }
  buf.pop_back(), undo();
  return r - 1;
}
