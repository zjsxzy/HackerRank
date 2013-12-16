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

const int MOD = 1000000007;
const int inf = 0x3f3f3f3f;
const int maxn = 25;
const int maxs = 1 << 8;
LL dp[maxn][maxs][maxs];
int state[maxn];
int cur, nxt;
int n, m, initJ, initK;

bool valid(int mask, int pos) {
	return (mask & (1 << pos)) == 0;
}

void dfs(int dep, int s1, int s2, int s3, int current) {
	if (current >= (1 << m)) return;
	if (current == (1 << m) - 1) {
		dp[nxt][s2][s3] = (dp[nxt][s2][s3] + dp[cur][initJ][initK]) % MOD;
		return;
	}
	if (s1 & (1 << dep)) {
		dfs(dep + 1, s1, s2, s3, current);
	} else {
		// ### <- dep
		//   #
		if (dep + 1 < m && valid(s2, dep) && valid(s3, dep) && valid(s3, dep + 1)) {
			dfs(dep + 1, s1, s2 | (1 << dep), s3 | (1 << dep) | (1 << (dep + 1)), current | (1 << dep));
		}
		//   # 
		// ### <- dep
		if (dep >= 1 && valid(s2, dep) && valid(s3, dep) && valid(s3, dep - 1)) {
			dfs(dep + 1, s1, s2 | (1 << dep), s3 | (1 << dep) | (1 << (dep - 1)), current | (1 << dep));
		}
		// #   <- dep
		// ###
		if (dep + 1 < m && valid(s1, dep + 1) && valid(s2, dep + 1) && valid(s3, dep + 1)) {
			dfs(dep + 2, s1, s2 | (1 << (dep + 1)), s3 | (1 << (dep + 1)), current | (1 << dep) | (1 << (dep + 1)));
		}
		// ### <- dep
		// #  
		if (dep + 1 < m && valid(s1, dep + 1) && valid(s2, dep) && valid(s3, dep)) {
			dfs(dep + 2, s1, s2 | (1 << dep), s3 | (1 << dep), current | (1 << dep) | (1 << (dep + 1)));
		}
		// ## <- dep
		//  #
		//  #
		if (dep + 2 < m && valid(s2, dep) && valid(s2, dep + 1) && valid(s2, dep + 2)) {
			dfs(dep + 1, s1, s2 | (1 << dep) | (1 << (dep + 1)) | (1 << (dep + 2)), s3, current | (1 << dep));
		}
		//  #
		//  #
		// ## <- dep
		if (dep >= 2 && valid(s2, dep) && valid(s2, dep - 1) && valid(s2, dep - 2)) {
			dfs(dep + 1, s1, s2 | (1 << (dep - 2)) | (1 << (dep - 1)) | (1 << dep), s3, current | (1 << dep));
		}
		// ## <- dep
		// #
		// #
		if (dep + 2 < m && valid(s2, dep) && valid(s1, dep + 1) && valid(s1, dep + 2)) {
			dfs(dep + 3, s1, s2 | (1 << dep), s3, current | (1 << dep) | (1 << (dep + 1)) | (1 << (dep + 2)));
		}
		// #  <- dep
		// #
		// ##
		if (dep + 2 < m && valid(s1, dep + 1) && valid(s1, dep + 2) && valid(s2, dep + 2)) {
			dfs(dep + 3, s1, s2 | (1 << (dep + 2)), s3, current | (1 << dep) | (1 << (dep + 1)) | (1 << (dep + 2)));
		}
	}
}

char str[10];
int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		memset(state, 0, sizeof(state));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			for (int j = 0; j < m; j++) {
				if (str[j] == '#') {
					state[i] |= (1 << j);
				}
			}
		}
		if (n == 1) {
			if (state[1] == (1 << m) - 1) puts("1");
			else puts("0");
			continue;
		}

		memset(dp, 0, sizeof(dp));
		dp[2][state[1]][state[2]] = 1;
		for (int i = 2; i <= n; i++) {
			cur = i, nxt = i + 1;
			for (int j = 0; j < (1 << m); j++) {
				for (int k = 0; k < (1 << m); k++) {
					if (dp[cur][j][k] == 0) continue;
					initJ = j; initK = k;
					dfs(0, j, k, state[i + 1], j);
				}
			}
		}
		cout << dp[n + 1][(1 << m) - 1][0] << endl;
	}
	return 0;
}

