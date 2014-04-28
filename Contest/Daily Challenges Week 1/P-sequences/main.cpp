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
const int MAXN = 100000;
int N, P;
LL dp[2][MAXN], sum[2][MAXN], sz[MAXN];

void solve(LL n, LL p) {
	int block = floor(sqrt(p));
	for (int i = 1; i <= block; i++)
		sz[i] = 1;
	int tp = p / (block + 1);
	while (tp) {
		sz[++block] = p / tp - p / (tp + 1);
		tp--;
	}
	memset(dp, 0, sizeof(p));
	for (int i = 1; i <= block; i++) {
		dp[0][i] = sz[i];
		sum[0][i] = sum[0][i - 1] + dp[0][i];
	}
	int cur = 0, nxt = 1;
	for (int i = 1; i < n; i++) {
		memset(dp[nxt], 0, sizeof(dp[nxt]));
		memset(sum[nxt], 0, sizeof(sum[nxt]));
		for (int j = 1; j <= block; j++) {
			dp[nxt][j] = sum[cur][block + 1 - j] * sz[j] % MOD;
			sum[nxt][j] = (sum[nxt][j - 1] + dp[nxt][j]) % MOD;
		}
		cur ^= 1; nxt ^= 1;
	}
	cout << sum[cur][block] << endl;
}
int main() {
	scanf("%d%d", &N, &P);
	solve(N, P);
	return 0;
}

