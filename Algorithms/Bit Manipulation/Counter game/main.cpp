#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    int first = -1, cnt = 0;
    for (int i = 0; i < 64; i++) {
        if ((n >> i) & 1) {
            cnt++;
            if (first == -1) first = i;
        }
    }
    cnt += first - 1;
    // cout << cnt << endl;
    if (cnt & 1) cout << "Louise" << endl;
    else cout << "Richard" << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

