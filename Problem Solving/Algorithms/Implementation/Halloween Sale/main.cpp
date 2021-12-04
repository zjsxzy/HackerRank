#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;
    int res = 0, price = p;
    while (s > 0) {
        if (s < price) break;
        s -= price;
        res++;
        if (price > m) price = max(m, price - d);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

