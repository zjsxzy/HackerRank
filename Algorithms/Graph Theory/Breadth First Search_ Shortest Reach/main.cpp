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

const int MAXN = 1000 + 5;
int n, m;
vector<int> adj[MAXN];
int dis[MAXN];
int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		int s;
		cin >> s;
		s--;
		queue<int> q;
		q.push(s);
		memset(dis, -1, sizeof(dis));
		dis[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			// cout << u << " " << dis[u] << endl;
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				if (dis[v] == -1) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (i == s) continue;
			printf("%d ", dis[i] == -1 ? dis[i] : dis[i] * 6);
		}
		puts("");
		for (int i = 0; i < n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}
