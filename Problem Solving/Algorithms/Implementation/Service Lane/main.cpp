#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (t--) {
        int l, r;
        cin >> l >> r;
        int res = INT_MAX;
        for (int i = l; i <= r; i++) {
            res = min(res, a[i]);
        }
        cout << res << endl;
    }
}

int main() {
    solve();
    return 0;
}

