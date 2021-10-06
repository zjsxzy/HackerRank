#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    LL n;
    cin >> n;
    unsigned long long cnt = 1, tot = 0;
    for (auto& x: primes) {
        cnt *= (LL)x;
        if (cnt > n) {
            cout << tot << endl;
            return;
        }
        tot++;
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

