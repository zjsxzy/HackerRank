#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int MAX_N = 100+5;
int N, dp[MAX_N][MAX_N], g[MAX_N][MAX_N][3];
char str[MAX_N];

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		scanf("%s", str + 1);
		N = strlen(str + 1);

		memset(g, 0, sizeof(g));
		for (int l = N; l >= 1; l--)
		for (int r = l; r <= N; r++) {
			dp[l][r] = r - l + 1;
			if (r == l) g[l][r][str[l] - 'a'] = 1;
			for (int m = l; m < r; m++) 
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
			for (int m = l; m < r; m++)
			for (int x = 0; x < 3; x++)
				if ((g[l][m][(x+1)%3] && g[m+1][r][(x+2)%3]) || (g[l][m][(x+2)%3] && g[m+1][r][(x+1)%3]))
					g[l][r][x] = 1, dp[l][r] = 1;
		}

		printf("%d\n", dp[1][N]);
	}
	return 0;
}
