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
int n;
int B[MAXN], dp[MAXN][2];

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", B + i);
		}
		dp[0][0] = dp[0][1] = 0;
		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + abs(1 - B[i - 1]));
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + abs(B[i] - 1));
		}
		printf("%d\n", max(dp[n - 1][0], dp[n - 1][1]));
	}
	return 0;
}

