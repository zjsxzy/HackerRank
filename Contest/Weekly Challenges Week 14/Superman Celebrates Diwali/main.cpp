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

const int MAXN = 1900 + 5;
int H, N, I;
int people[MAXN][MAXN], dp[MAXN][MAXN];
int rescue[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d%d", &N, &H, &I);
	for (int i = 1; i <= N; i++) {
		int u;
		scanf("%d", &u);
		for (int j = 0; j < u; j++) {
			int x;
			scanf("%d", &x);
			people[x][i]++;
		}
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		dp[H][i] = people[H][i];
		rescue[H] = max(rescue[H], people[H][i]);
	}
	for (int h = H - 1; h >= 1; h--) {
		for (int i = 1; i <= N; i++) {
			dp[h][i] = dp[h + 1][i];
			if (h + I <= H) {
				dp[h][i] = max(dp[h][i], rescue[h + I]);
			}
			dp[h][i] += people[h][i];
			rescue[h] = max(rescue[h], dp[h][i]);
		}
	}
	printf("%d\n", rescue[1]);
	return 0;
}