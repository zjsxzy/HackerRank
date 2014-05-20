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

const int maxn = 21;
struct state {
	int x, y, s;
	state() {}
	state(int x, int y, int s) : x(x), y(y), s(s) {}
};
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
char mat[maxn][maxn];
int w, h, cnt, sx, sy;
int dis[maxn][maxn][1 << 11];
int idx[maxn][maxn];

bool valid(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w && mat[x][y] != 'x';
}

void bfs() {
	queue<state> q;
	q.push(state(sx, sy, 0));
	memset(dis, -1, sizeof(dis));
	dis[sx][sy][0] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, s = q.front().s;
		q.pop();
		if (s == (1 << cnt) - 1) {
			printf("%d\n", dis[x][y][s]);
			return;
		}
		for (int k = 0; k < 4; k++) {
			int newx = x + dx[k], newy = y + dy[k];
			if (!valid(newx, newy)) continue;
			int news = idx[newx][newy] == -1 ? s : s | (1 << idx[newx][newy]);
			if (dis[newx][newy][news] == -1) {
				dis[newx][newy][news] = dis[x][y][s] + 1;
				q.push(state(newx, newy, news));
			}
		}
	}
	printf("-1\n");
}

int main() {
	while (~scanf("%d%d", &w, &h)) {
		memset(idx, -1, sizeof(idx));
		cnt = 0;
		for (int i = 0; i < h; i++) {
			scanf("%s", mat[i]);
			for (int j = 0; j < w; j++) {
				if (mat[i][j] == 'o') {
					sx = i; sy = j;
				}
				else if (mat[i][j] == '*') idx[i][j] = cnt++;
			}
		}
		bfs();
	}
	return 0;
}
