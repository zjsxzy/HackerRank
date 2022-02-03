#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x: p) cin >> x;
    stack<pair<int, int>> st;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int day = 0;
        while (!st.empty() && st.top().first >= p[i]) {
            int t = st.top().second;
            st.pop();
            day = max(day, t);
        }
        if (!st.empty()) day += 1;
        else day = 0;
        res = max(res, day);
        st.emplace(p[i], day);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

