#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for (auto &s : vec) {
        cin >> s;
    }

    sort(vec.begin(), vec.end(), [](const string &a, const string &b) {
            return (a.size() < b.size()) || (a.size() == b.size() && a < b);
    });

    for (auto &s : vec) {
        cout << s << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

