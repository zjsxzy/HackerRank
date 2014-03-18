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

const int MAXN = 105;
const int BASE = 10000;
int n, G;
int a[MAXN];
bool dp[MAXN][(BASE << 1) + 5];

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &G);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			sum += a[i];
		}
		memset(dp, false, sizeof(dp));
		dp[0][BASE + a[0]] = true;
		dp[0][BASE - a[0]] = true;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= BASE << 1; j++) {
				if (dp[i - 1][j] == false) continue;
				if (j - a[i] >= 0) dp[i][j - a[i]] = true;
				if (j + a[i] <= BASE << 1) dp[i][j + a[i]] = true;
			}
		}
		int ret = -1;
		for (int i = 0; i <= BASE; i++) {
			if (dp[n - 1][BASE - i] || dp[n - 1][BASE + i]) {
				ret = (sum + i) / 2;
				break;
			}
		}
		puts(ret <= G ? "YES" : "NO");
	}
	return 0;
}

