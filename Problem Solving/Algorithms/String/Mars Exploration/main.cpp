#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string str;
    cin >> str;
    string target = "SOS";
    int res = 0;
    for (int i = 0; i < SZ(str); i++) {
        if (str[i] != target[i % 3]) {
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

