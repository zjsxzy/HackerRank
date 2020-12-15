#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> station(m);
    for (int i = 0; i < m; i++) {
        cin >> station[i];
    }
    sort(station.begin(), station.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(station.begin(), station.end(), i);
        if (*it == i) continue;
        if (it == station.end()) {
            it--;
            res = max(res, i - *it);
        }
        int d = *it - i;
        if (it != station.begin()) {
            it--;
            d = min(d, i - *it);
        }
        res = max(res, d);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

