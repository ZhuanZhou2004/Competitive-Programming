#include <bits/stdc++.h>
#include "dsu.h"
using namespace std;

int n, m, limit;

void init(int nn, int mm, int limits) {
  n = nn, m = mm, limit = limits;
}
int solve(int l) {
//  printf("solve %d\n",l);
  int r = l;
  while (r <= m && check(r)) {
//    printf("r = %d, ok!\n", r);
    merge(r);
    r++;
  }
  for (int i = r - 1; i >= l; i--) {
    undo();
  }
  return r - 1;
}
