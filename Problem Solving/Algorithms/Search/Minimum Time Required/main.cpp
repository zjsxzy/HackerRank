#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL inf = 1e14;

void solve() {
    int n, goal;
    cin >> n >> goal;
    vector<LL> machines(n);
    for (auto &x: machines) {
        cin >> x;
    }
    LL lo = 0, hi = inf, res = -1;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        LL sum = 0;
        for (int i = 0; i < n; i++) {
            LL x = machines[i];
            sum += mid / x;
        }
        if (sum >= goal) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

