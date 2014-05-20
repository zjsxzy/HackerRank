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

int bitcnt(LL x) {
	int res = 0;
	for (; x; x = x & (x - 1), res++);
	return res;
}

LL calc(LL x) {
	if (x >= 0) {
		if (x == 0) return 0;
		if (!(x & 1)) return calc(x - 1) + bitcnt(x);
		return ((x + 1) >> 1) + 2ll * calc(x >> 1);
	} else {
		// ~(x) + 1 = -x => ~(x) = -x - 1
		return 32ll * (-x) - calc(-x - 1);
	}
}

LL solve(LL l, LL r) {
	if (l >= 0) {
		LL res = calc(r);
		if (l != 0)
			res -= calc(l - 1);
		return res;
	} else {
		LL res;
		if (r < 0)
			res = calc(l) - calc(r + 1);
		else res = calc(l) + calc(r);
		return res;
	}
}

int main() {
	int Test;
	cin >> Test;
	while (Test--) {
		LL ql, qr;
		cin >> ql >> qr;
		if (ql > qr) swap(ql, qr);
		LL res = solve(ql, qr);
		cout << res << endl;
	}
	return 0;
}
