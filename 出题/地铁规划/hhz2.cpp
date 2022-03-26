#include <bits/stdc++.h>
using namespace std;

void merge(int id) ;
bool check(int id) ;
void undo() ;
void init(int, int, int) ;
int solve(int l) ;
int n, r;
int S[200010], sta[200010], pos[200010];
int top, tops;
inline void _merge(int x) {
    sta[++top] = x;
    merge(x);
}
inline int _undo() {
    undo();
    S[tops]--;
    if (S[tops] == 0) tops--;
    return sta[top--];
}
inline void __merge(int x) {
    ++top;
}
inline int __undo() {
    S[tops]--;
    if (S[tops] == 0) tops--;
    return sta[top--];
}
inline void real_pop(int l, vector < int > a, int x) {
    for (int i = 0; i < l; i++) a.push_back(_undo());
    sort(a.begin(), a.end(), greater < int > ());
    if (a.size() - 1) S[++tops] = a.size() - 1;
    for (auto i : a) if (i != x) _merge(i), pos[i] = tops;
}
inline vector < int > real_sort(int len, int chk) {
    vector < int > ans;
    if (sta[top] == chk) {
        for (int i = 0; i < len; i++) ans.push_back(_undo());
        return ans;
    }
    else {
        for (int i = 0, i_end = S[tops]; i < i_end; i++) ans.push_back(_undo());
        sort(ans.begin(), ans.end());
        int cnt = 0;
        while (ans.size() > len) _merge(ans.back()), ans.pop_back(), cnt++;
        if (cnt) S[++tops] = cnt;
    }
    return ans;
}
inline void _sort(int l, vector < int > a = vector < int > {}) {
    for (int i = 0; i < l; i++) a.push_back(__undo());
    if (a.size()) S[++tops] = a.size();
    for (auto i : a) __merge(i), pos[i] = tops;
}
inline void add(int x) {
    int sum = 1;
    for (int i = tops; i > 0; i--) if (sum * 1.7 > S[i]) sum += S[i];
    else break;
    _merge(x);
    S[++tops] = 1;
    _sort(sum);
}
inline void pop(int x) {
    int len = 0, tmp;
    vector < int > a;
    for (int i = pos[x] + 1; i <= tops; i++) len += S[i];
    for (int i = 0; i < len; i++) a.push_back(_undo());
    int qwqdel = len / 3;
    int sum = len + qwqdel;
    S[tops] -= qwqdel + 1;
    for (int i = tops; i > 0; i--) if (sum * 1.7 > S[i]) sum += S[i];
    else break;
    S[tops] += qwqdel + 1;
    vector < int > b = real_sort(min(S[tops], sum + 1 - (int)a.size()), x);
    a.insert(a.end(), b.begin(), b.end());
    real_pop(sum + 1 - a.size(), a, x);
}
int solve(int l) {
    while (r < n && check(r + 1)) add(++r);
    pop(l);
    return r;
}
void init(int, int m, int limits) {
    ::n = m;
}
