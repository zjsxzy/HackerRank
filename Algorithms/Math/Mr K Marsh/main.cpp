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

const int maxn = 505;
char mat[maxn][maxn];
int n, m;
int sum[maxn][maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", mat[i] + 1);
		sum[i][0] = 0;
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i][j - 1] + (mat[i][j] == 'x');
		}
	}

	int res = 0;
	for (int i = 1; i <= m; i++) for (int j = i + 1; j <= m; j++) {
		int p = -1;
		for (int k = 1; k <= n; k++) {
			if (sum[k][j] - sum[k][i - 1] == 0) {
				if (p > 0) {
					res = max(res, 2 * (j - i + k - p));
				} else if (p == -1) p = k;
			} else if (mat[k][i] == 'x' || mat[k][j] == 'x') {
				p = -1;
			}
		}
	}
	if (res > 0)
		printf("%d\n", res);
	else {
		puts("impossible");
	}
	return 0;
}
