#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt(), m = inf.readInt(), limit = inf.readInt();
    ans.readLine();
    string A = ouf.readLine();
    if (A != "Success") quitf(_wa, "Invalid Solution.");
    ans.readLine();
    string tmp = ouf.readLine();
    for (int i = 1; i <= m; i++) {
        int a = ouf.readInt(1, m, "ri"), b = ans.readInt();
        if (a != b) quitf(_wa, "Wrong Answer.");
    }
    quitf(_ok, "Accepted.");
}
