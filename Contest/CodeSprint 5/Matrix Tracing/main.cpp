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

const LL MOD = 1000000000 + 7;
const int MAXN = 2000000;
int n, m;
LL mul[MAXN], rmul[MAXN];

// x ^ b mod MOD
LL quickpow(LL x, LL b) {
	LL ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

void pre() {
	mul[1] = rmul[1] = 1 % MOD;
	for (int i = 2; i <= MAXN; i++) {
		mul[i] = mul[i - 1] * i % MOD;
		if (i <= MAXN / 2) {
			rmul[i] = rmul[i - 1] * quickpow(i, MOD - 2) % MOD;
		}
	}
}

int main() {
	pre();
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> n >> m;
		if (n == 1 || m == 1) {
			puts("1");
		} else {
			n--; m--;
			LL ret = mul[n + m] * rmul[n] % MOD * rmul[m] % MOD; 
			cout << ret << endl;
		}
	}
	return 0;
}

