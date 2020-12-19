#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string str;
    cin >> str;
    while (true) {
        bool flag = false;
        for (int i = 0; i < SZ(str) - 1; i++) {
            if (str[i] == str[i + 1]) {
                flag = true;
                str = str.erase(i, 2);
                break;
            }
        }
        if (!flag) break;
    }
    if (SZ(str) == 0) cout << "Empty String" << endl;
    else cout << str << endl;
}

int main() {
    solve();
    return 0;
}

