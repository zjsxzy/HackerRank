#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string str;
    cin >> str;
    string target = "hackerrank";
    int target_index = 0;
    for (int i = 0; i < SZ(str); i++) {
        if (str[i] == target[target_index]) {
            target_index++;
            if (target_index == SZ(target)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

