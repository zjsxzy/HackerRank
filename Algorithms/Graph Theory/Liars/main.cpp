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
const int inf = 0x3f3f3f3f;
int n, m;
int dis[maxn];
bool vis[maxn];
vector<pair<int, int> > adj[maxn];

void addEdge(int a, int b, int c) {
//	cout << a << " -> " << b << " " << c << endl;
	adj[a].PB(MP(b, c));
}

int spfa(int st, int ed) {
	for (int i = 0; i <= n; i++) {
		dis[i] = inf;
		vis[i] = false;
	}
	dis[st] = 0;
	vis[st] = true;	
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, tmp = dis[u] + adj[u][i].second;
			if (tmp < dis[v]) {
				dis[v] = tmp;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dis[ed];
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a - 1, b, c);
			addEdge(b, a - 1, -c);
		}
		for (int i = 0; i < n; i++) {
			addEdge(i, i + 1, 1);
			addEdge(i + 1, i, 0);
		}

		int Lmin = -spfa(n, 0);
		int Lmax = spfa(0, n);
		printf("%d %d\n", Lmin, Lmax);

		for (int i = 0; i <= n; i++) adj[i].clear();
	}
	return 0;
}
