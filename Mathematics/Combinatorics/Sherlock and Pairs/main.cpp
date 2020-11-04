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
#include <cassert>
#include <climits>
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

const int MAXN = 100000 + 5;
int n;
int d[MAXN * 10];
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
		memset(d, 0, sizeof(d));
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            d[x]++;
        }
        LL res = 0;
        for (int i = 0; i <= 1000000; i++) {
            if (d[i] > 0) {
				// cout << i << " " << d[i] << endl;
                res += (LL)d[i] * (d[i] - 1);
            }
        }
        cout << res << endl;
    }
	return 0;
}

