#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string str;
    cin >> str;
    int sum = 0;
    for (int i = 0, j; i < SZ(str); i = j) {
        j = i + 1;
        while (j < SZ(str) && str[i] == str[j]) {
            j++;
        }
        sum++;
    }
    cout << str.size() - sum << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

