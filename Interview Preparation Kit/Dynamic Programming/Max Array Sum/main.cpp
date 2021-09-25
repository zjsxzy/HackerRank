#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x: arr) {
        cin >> x;
    }
    int res = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
        if (i - 1 >= 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        if (i - 2 >= 0) {
            dp[i] = max(dp[i], dp[i - 2] + arr[i]);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

