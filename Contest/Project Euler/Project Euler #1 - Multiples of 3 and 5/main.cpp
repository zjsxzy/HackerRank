#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL d = (n - 1) / 3;
    LL res = (1 + d) * d * 3 / 2;
    d = (n - 1) / 5;
    res += (1 + d) * d * 5 / 2;
    d = (n - 1) / 15;
    res -= (1 + d) * d * 15 / 2;
    cout << res << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

