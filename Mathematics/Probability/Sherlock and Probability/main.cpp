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
int N, K;
char str[MAXN];
int sum[MAXN];

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &N, &K);
		scanf("%s", str + 1);
		sum[0] = 0;
		for (int i = 1; i <= N; i++) {
			sum[i] = sum[i - 1] + (str[i] == '1');
		}
		LL tot = 0;
		for (int i = 1; i <= N; i++) {
			if (str[i] == '0') continue;
			int a = max(1, i - K), b = min(N, i + K);
			LL k = sum[b] - sum[a - 1];
			tot += k;
		}
		if (tot == 0) {
			printf("0/1\n");
			continue;
		}
		LL g = gcd(tot, (LL)N * N);
		printf("%lld/%lld\n", tot / g, (LL)N * N / g);
	}
	return 0;
}

