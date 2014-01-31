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

const int MAXN = 100 + 5;
int n, m;
LL C[MAXN][MAXN][MAXN];
LL cur[MAXN][MAXN][MAXN];

int lowbit(int x) {
	return x & (-x);
}

LL sum (int x , int y , int z) {
	LL ans = 0;
	for (int i = x ; i > 0 ; i -= lowbit(i))
		for (int j = y ; j > 0 ; j -= lowbit(j))
			for (int k = z ; k > 0 ; k -= lowbit(k))
				ans += C[i][j][k];
	return ans;
}

void add(int x , int y , int z , LL num) {
	for (int i = x ; i <= n ; i += lowbit(i))
		for (int j = y ; j <= n ; j += lowbit(j))
			for (int k = z ; k <= n ; k += lowbit(k))
				C[i][j][k] += num;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &m);
		memset(C, 0, sizeof(C));
		memset(cur, 0, sizeof(cur));
		for (int i = 0; i < m; i++) {
			char str[10];
			scanf("%s", str);
			if (*str == 'U') {
				int x, y, z, k;
				scanf("%d%d%d%d", &x, &y, &z, &k);
				add(x, y, z, k - cur[x][y][z]);
				cur[x][y][z] = k;
			} else {
				int x1, y1, z1, x2, y2, z2;
				scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
				LL res = sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)-sum(x2,y2,z1-1)+sum(x1-1,y1-1,z2)+sum(x1-1,y2,z1-1)+sum(x2,y1-1,z1-1)-sum(x1-1,y1-1,z1-1);
				printf("%lld\n", res);
			}
		}
	}
	return 0;
}
