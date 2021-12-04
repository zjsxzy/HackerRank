#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n);
    int lastAnswer = 0;
    vector<int> ans;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            int idx = (x ^ lastAnswer) % n;
            arr[idx].push_back(y);
        } else {
            int idx = (x ^ lastAnswer) % n;
            lastAnswer = arr[idx][y % arr[idx].size()];
            ans.push_back(lastAnswer);
        }
    }
    for (auto &x: ans) {
        cout << x << endl;
    }
}

int main() {
    solve();
    return 0;
}

