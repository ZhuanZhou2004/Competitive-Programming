#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main() {
    registerValidation();
    int n = inf.readInt(2, 100000, "n");
    inf.readSpace();
    int m = inf.readInt(2, 200000, "m");
    inf.readSpace();
    int lim = inf.readInt(n <= 1000 && m <= 1000 ? 1000000 : 5000000, 5000000, "lim");
    inf.readEoln();
    for (int i = 1; i <= m; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();
        ensuref(u != v, "u == v");
    }
    inf.readEof();
}
