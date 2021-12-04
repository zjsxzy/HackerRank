#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    for (auto &c : s) {
        if (c >= 'A' && c <= 'Z') res++;
    }
    cout << res + 1 << endl;
}

int main() {
    solve();
    return 0;
}

