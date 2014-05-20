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

const int inf = 0x3f3f3f3f;
const int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
const int dy[8] = {-1, 1, 0, 0, 1, -1, -1, 1};
int n, m;
int mat[22][22];
int dis[22][22];
bool vis[22][22];

bool valid(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &mat[i][j]);
				dis[i][j] = inf;
			}
		}
		memset(vis, 0, sizeof(vis));
		queue<pair<int, int> > q;
		for (int j = 1; j <= m; j++) {
			q.push(MP(1, j));
			dis[1][j] = mat[1][j];
			vis[1][j] = true;
		}
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			vis[x][y] = false;
			for (int k = 0; k < 8; k++) {
				int xx = x + dx[k], yy = y + dy[k];
				if (!valid(xx, yy)) continue;
				if (dis[x][y] + mat[xx][yy] < dis[xx][yy]) {
					dis[xx][yy] = dis[x][y] + mat[xx][yy];
					if (!vis[xx][yy]) {
						vis[xx][yy] = true;
						q.push(MP(xx, yy));
					}
				}
			}
		}
		int ret = inf;
		for (int j = 1; j <= m; j++)
			ret = min(ret, dis[n][j]);
		printf("%d\n", ret);
	}
	return 0;
}

