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
typedef long long LL;

void solve() {
    long long d, p;
	cin >> d >> p;
	if (d < 0) {
		cout << 0 << endl;
		return;
	} else if (d == 0 && p == 0) {
        cout << 1 << endl;
        return;
    }
    long long t = d * d + 4LL * p;
    if ((long long)sqrt(t) * (long long)sqrt(t) == t) {
        int res = 2;
        if (d && t) res += 2;
        cout << res << endl;
    } else {
        cout << 0 << endl;
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
