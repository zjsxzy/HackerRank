#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 10000005;
const LL inf = 1LL << 60;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vec;
    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        vec.emplace_back(l, k);
        vec.emplace_back(r + 1, -k);
    }
    sort(vec.begin(), vec.end());
    LL sum = 0, res = -inf;
    for (auto &p: vec) {
        sum += p.second;
        res = max(res, sum);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

