#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int money, n;
    cin >> money >> n;
    map<int, vector<int>> idx;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        idx[cost[i]].emplace_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        int x = cost[i], y = money - cost[i];
        if (x != y) {
            if (idx.find(y) != idx.end()) {
                cout << i + 1 << " " << idx[y][0] << endl;
                return;
            }
        } else {
            if (idx[x].size() >= 2) {
                cout << i + 1 << " " << idx[y][1] << endl;
                return;
            }
        }
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

