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

const int maxn = 105;
int n;
char str[maxn];
int dp[maxn][maxn][3];

int main() {
	int Test;
	scanf("%d", &Test);
	for (; Test--; ) {
		scanf("%s", str + 1);
		n = strlen(str + 1);
		memset(dp, -1, sizeof(dp));
		for (int l = n; l >= 1; l--) {
			for (int r = l; r <= n; r++) {
				if (l == r) dp[l][r][str[l] - 'a'] = 1;
				for (int mid = l; mid < r; mid++) {
					// same color
					for (int x = 0; x < 3; x++) {
						if (dp[l][mid][x] != -1 && dp[mid + 1][r][x] != -1)
							if (dp[l][r][x] == -1 || dp[l][r][x] > dp[l][mid][x] + dp[mid + 1][r][x])
								dp[l][r][x] = dp[l][mid][x] + dp[mid + 1][r][x];
					}
					// different color
					for (int x = 0; x < 3; x++) {

						int Left = dp[l][mid][(x+1)%3], Right = dp[mid+1][r][(x+2)%3];
						if (Left != -1 && Right != -1) {
							if ((Left & 1) && (Right & 1)) {
								dp[l][r][x] = 1;
							} else if (!(Left & 1) && !(Right & 1)) {
								if (dp[l][r][(x+1)%3] == -1 || dp[l][r][(x+1)%3] > 2)
									dp[l][r][(x+1)%3] = 2;
								if (dp[l][r][(x+2)%3] == -1 || dp[l][r][(x+2)%3] > 2)
									dp[l][r][(x+2)%3] = 2;
							} else {
								if ((Left & 1) && !(Right & 1)) {
									dp[l][r][(x+1)%3] = 1;
								} else {
									dp[l][r][(x+2)%3] = 1;
								}
							}
						}
						
						Left = dp[l][mid][(x+2)%3], Right = dp[mid+1][r][(x+1)%3];
						if (Left != -1 && Right != -1) {
							if ((Left & 1) && (Right & 1)) {
								dp[l][r][x] = 1;
							} else if (!(Left & 1) && !(Right & 1)) {
								if (dp[l][r][(x+1)%3] == -1 || dp[l][r][(x+1)%3] > 2)
									dp[l][r][(x+1)%3] = 2;
								if (dp[l][r][(x+2)%3] == -1 || dp[l][r][(x+2)%3] > 2)
									dp[l][r][(x+2)%3] = 2;
							} else {
								if ((Left & 1) && !(Right & 1)) {
									dp[l][r][(x+2)%3] = 1;
								} else {
									dp[l][r][(x+1)%3] = 1;
								}
							}
						}
						
					}
				}
			}
		}
		int res = n;
		for (int x = 0; x < 3; x++)
			if (dp[1][n][x] != -1) res = min(res, dp[1][n][x]);
		printf("%d\n", res);
	}
	return 0;
}
