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

int comb(int n) {
	return n < 2 ? 0 : n * (n - 1) / 2;
}

int calc(int m, int n) {
	int sz = n / m, r = n % m;
	int most = comb(m) * sz + comb(r);
	most += comb(sz) * m * (m - 1);
	most += r * (m - 1) * sz;
	return most;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int lo = 1, hi = n + 1, ret = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (calc(mid, n) >= k) {
				ret = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		printf("%d\n", ret);
	}
	return 0;
}

