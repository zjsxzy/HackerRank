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
bool flag[32];

// x ^ b
LL quickpow(LL x, LL b) {
	LL ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		int n;
		scanf("%d", &n);
		memset(flag, false, sizeof(flag));
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			for (int k = 0; k < 31; k++) {
				if (x & (1 << k)) {
					flag[k] = true;
				}
			}
		}
		LL ret = 0, cnt = quickpow(2, n - 1);
		for (int k = 0; k < 31; k++) {
			if (!flag[k]) continue;
			ret = (ret + cnt * (1ll << k) % MOD) % MOD;
		}
		cout << ret << endl;
	}
	return 0;
}
