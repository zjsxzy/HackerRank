#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL k;
    cin >> k;
    cout << k / 2 * (k - k / 2) << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

