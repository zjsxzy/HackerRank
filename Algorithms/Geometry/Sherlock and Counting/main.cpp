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

int n, k;
int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &k);
		int lo = 1, hi = n / 2, ret = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if ((LL)mid * (n - mid) <= (LL)n * k) {
				ret = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (ret == 0) cout << ret << endl;
		else cout << 2 * ret - (ret + ret == n) << endl;
	}
	return 0;
}

