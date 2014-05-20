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

const int MAXN = 100000 + 5;
const LL MOD = 1000000007;
int phi[MAXN];
int v[505];

int Euler(int n) {
	int ret = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			n /= i;
			ret *= (i - 1);
			while (n % i == 0)
				n /= i, ret *= i;
		}
	}
	if (n > 1) ret *= n - 1;
	return ret;
}

int main() {
	for (int i = 1; i < MAXN; i++) {
		phi[i] = Euler(i);
	}
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		int k;
		scanf("%d", &k);
		int Min = MAXN;
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
			Min = min(Min, v[i]);
		}
		LL sum = 0;
		for (int d = 1; d <= Min; d++) {
			LL prod = 1;
			for (int i = 0; i < k; i++) {
				int val = v[i] / d;
				prod = prod * val % MOD;
			}
			sum = (sum + prod * phi[d]) % MOD;
		}
		printf("%lld\n", sum);
	}
	return 0;
}

