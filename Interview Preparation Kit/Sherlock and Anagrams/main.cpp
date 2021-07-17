#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        map<string, int> cnt;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string sub = s.substr(i, j - i + 1);
                sort(sub.begin(), sub.end());
                cnt[sub]++;
            }
        }
        int res = 0;
        for (auto &[k, v]: cnt) {
            res += v * (v - 1) / 2;
        }
        cout << res << endl;
    }
}

int main() {
    solve();
    return 0;
}

