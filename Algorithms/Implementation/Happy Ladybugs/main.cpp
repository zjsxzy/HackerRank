#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        if (s[i] != '_') cnt[s[i]]++;
    }
    bool all_happy = true;
    bool empty_cell = false;
    for (int i = 0; i < n; i++) {
        bool happy = false;
        if (s[i] == '_') {
            empty_cell = true;
            continue;
        }
        if (i + 1 < n && s[i + 1] == s[i]) happy = true;
        if (i - 1 >= 0 && s[i - 1] == s[i]) happy = true;
        if (!happy) all_happy = false;
    }
    if (all_happy) {
        cout << "YES" << endl;
    } else {
        if (!empty_cell) {
            cout << "NO" << endl;
        } else {
            bool count_one = false;
            for (auto& [c, v] : cnt) {
                if (v == 1) {
                    count_one = true;
                    break;
                }
            }
            cout << (count_one ? "NO" : "YES") << endl;
        }
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

