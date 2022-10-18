#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                prev[i][j] = {i - 1, j - 1};
            } else {
                if (dp[i - 1][j] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j] = {i - 1, j};
                }
                if (dp[i][j - 1] > dp[i][j]) {
                    dp[i][j] = dp[i][j - 1];
                    prev[i][j] = {i, j - 1};
                }
            }
        }
    }
    vector<int> ans;
    function<void(int, int)> dfs = [&](int i, int j) {
        if (i == 0 || j == 0) return;
        if (i - prev[i][j].first == 1 && j - prev[i][j].second == 1) ans.push_back(a[i - 1]);
        dfs(prev[i][j].first, prev[i][j].second);
    };
    dfs(n, m);
    reverse(ans.begin(), ans.end());
    for (auto x: ans) cout << x << ' ';
    cout << endl;
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

