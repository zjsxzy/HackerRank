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

const LL MOD = 1000000007;
LL quickpow(LL x, int b) {
	LL ret = 1ll;
	for (; b; b >>= 1) {
		if (b & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

bool valid(int a, int b) {
	if (a == 25) return b < 24;
	if (b == 25) return a < 24;
	if (a > 25 || b > 25) return abs(a - b) == 2;
	return false;
}

// n choose m; n > m
LL comb(int n, int m) {
	LL ret = 1;
	for (int i = n; i > n - m; i--) {
		ret = ret * i % MOD;
	}
	for (int i = 2; i <= m; i++) {
		//cout << quickpow(i, MOD - 2) << endl;
		ret = ret * quickpow(i, MOD - 2) % MOD;
	}
	return ret;
}

LL calc(int a, int b) {
	if (a == 25) {
		return comb(a + b - 1, b);
	}
	if (b == 25) {
		return comb(a + b - 1, a);
	}
	if (a > 25 || b > 25) {
		LL ret = comb(48, 24);
		ret = ret * quickpow(2, min(a, b) - 24) % MOD;
		return ret;
	}
	return -1;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (!valid(a, b)) {
		puts("0");
	} else {
		LL ret = calc(a, b);
		cout << ret << endl;
	}
	return 0;
}
