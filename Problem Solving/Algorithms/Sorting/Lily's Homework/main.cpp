#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<int> b(a);
    sort(b.begin(), b.end());
    unordered_map<int, int> val2pos;
    auto solve = [&]() {
        int ans = 0;
        vector<int> arr(a);
        for (int i = 0; i < n; i++) {
            val2pos[a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == b[i]) continue;
            int x = arr[i], y = b[i];
            swap(arr[i], arr[val2pos[y]]);
            ans++;
            val2pos[x] = val2pos[y];
            val2pos[y] = i;
        }
        return ans;
    };
    int res = solve();
    reverse(b.begin(), b.end());
    res = min(res, solve());
    cout << res << endl;
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

