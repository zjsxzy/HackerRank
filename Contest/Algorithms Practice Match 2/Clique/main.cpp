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

int calc(int m, int n) {
	int g1 = n % m;
	int g2 = m - g1;
	int sz1 = n / m + 1;
	int sz2 = n / m;
	return g1 * sz1 * g2 * sz2 + g1 * (g1 - 1) * sz1 * sz1 / 2 + g2 * (g2 - 1) * sz2 * sz2 / 2;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int lo = 1, hi = n + 1, ret = -1;
		while (lo + 1 < hi) {
			int mid = lo + (hi - lo) / 2;
			if (calc(mid, n) < k) {
				lo = mid;
			} else hi = mid;
		}
		printf("%d\n", hi);
	}
	return 0;
}

