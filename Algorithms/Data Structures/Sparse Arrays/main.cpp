#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<string, int> cnt;
    while (n--) {
        string s;
        cin >> s;
        cnt[s]++;
    }
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << cnt[s] << endl;
    }
}

int main() {
    solve();
    return 0;
}

