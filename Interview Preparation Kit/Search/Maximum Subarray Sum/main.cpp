#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL n, m;
    cin >> n >> m;
    set<LL> st;
    st.insert(0);
    LL prefix = 0, res = 0;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        prefix = (prefix + x) % m;
        res = max(res, prefix);
        auto it = st.lower_bound(prefix + 1);
        if (it != st.end()) {
            res = max(res, prefix - *it + m);
        }
        st.insert(prefix);
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

