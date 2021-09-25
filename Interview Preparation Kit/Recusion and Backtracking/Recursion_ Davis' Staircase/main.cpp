#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 1e10 + 7;
void solve() {
    int n;
    cin >> n;
    vector<LL> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i - 1 >= 0) {
            f[i] += f[i - 1];
            f[i] %= mod;
        }
        if (i - 2 >= 0) {
            f[i] += f[i - 2];
            f[i] %= mod;
        }
        if (i - 3 >= 0) {
            f[i] += f[i - 3];
            f[i] %= mod;
        }
    }
    cout << f[n] << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

