#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<pair<char, int>> vec;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            vec.emplace_back(s[i - 1], cnt);
            cnt = 1;
        }
    }
    vec.emplace_back(s[n - 1], cnt);
    LL res = 0;
    for (int i = 0; i < vec.size(); i++) {
        res += vec[i].second * (vec[i].second + 1) / 2;
        if (i - 1 >= 0 && i + 1 < n) {
            if (vec[i - 1].first == vec[i + 1].first && vec[i - 1].first != vec[i].first && vec[i].second == 1) {
                res += min(vec[i - 1].second, vec[i + 1].second);
            }
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

