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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] & 1) {
            res++;
            b[i]++;
            b[i + 1]++;
        }
    }
    if (b[n - 1] & 1) {
        if (b[n - 2] & 1) {
            cout << 2 * (res + 1) << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << res * 2 << endl;
    }
}

int main() {
    solve();
    return 0;
}

