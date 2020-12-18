#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string str;
    cin >> str;
    vector<int> diff;
    for (int i = 0; i < SZ(str) - 1; i++) {
        diff.push_back(abs(str[i + 1] - str[i]));
    }
    reverse(str.begin(), str.end());
    for (int i = 0; i < SZ(str) - 1; i++) {
        int d = abs(str[i + 1] - str[i]);
        if (d != diff[i]) {
            cout << "Not Funny" << endl;
            return;
        }
    }
    cout << "Funny" << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

