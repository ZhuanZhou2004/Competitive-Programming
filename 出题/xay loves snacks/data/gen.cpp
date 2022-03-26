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

mt19937 rng(114514);
int n, m, seed;

int main() {
  for (int t = 1; t <= 20; t++) {
    if (t <= 2) n = 50, m = 100;
    else if (t <= 6) n = 50, m = rng() % 1001 + 9000;
    else if (t <= 7) n = 1e7, m = 95;
    else if (t <= 8) n = 114514, m = 1919810, seed = 19260817;
    else if (t <= 9) n = 1919810, m = 1000000, seed = 114514;
    else if (t <= 12) n = rng() & 1 ? rng() % (100000 - 50 + 1) + 50 : 50 + rng() % 20, m = rng() % 10000000 + 2;
    else if (t <= 16) n = rng() & 1 ? rng() % (10000000 - 50 + 1) + 50 : 50 + rng() % 20, m = rng() % 50000000 + 2;
    else n = rng() & 1 ? rng() % (10000000 - 50 + 1) + 50 : 50 + rng() % 20, m = rng() % 100000000 + 2;
    m = min(m, 100000000);
    if (t != 8 && t != 9) seed = rng() % INT_MAX;
    char in[15]; sprintf(in, "snacks%d.in", t);
    fstream fout(in, ios::out | ios::trunc);
    fout << n << ' ' << m << ' ' << seed << '\n'; 
    fout.close();
    char cmd[100]; sprintf(cmd, "snacks.exe < snacks%d.in > snacks%d.out", t, t);
    system(cmd);
    char out[15]; sprintf(out, "snacks%d.out", t);
    ifstream fin(out);
    int x; fin >> x;
    printf("Running on data #%d, input(n = %d, m = %d, seed = %d), output(ans = %d)\n", t, n, m, seed, x);
    fin.close();
  }
}
