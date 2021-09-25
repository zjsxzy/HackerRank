#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto& c: s) {
        cnt[c]++;
    }
    map<int, int> mp;
    for (auto& [k, v]: cnt) {
        mp[v]++;
    }
    if (mp.size() == 1) {
        cout << "YES" << endl;
    } else if (mp.size() == 2) {
        auto one = mp.begin();
        auto two = mp.end();
        two--;
        if (one->second == 1) {
            if (one->first == 1 || one->first == two->first + 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (two->second == 1) {
            if (two->first == 1 || two->first == one->first + 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    solve();
    return 0;
}

