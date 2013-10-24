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

const int maxn = 50005;
const int maxm = 500005;
const LL inf = 1ll << 60;
int n, m;
vector<pair<int, int> > adj[maxn];
LL dis[maxn];

LL dijkstra() {
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
	}
	dis[1] = 0;
	priority_queue<pair<LL, int> > pq;
	pq.push(MP(0, 1));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, tmp = max(dis[u], (LL)adj[u][i].second);
			if (tmp < dis[v]) {
				dis[v] = tmp;
				pq.push(MP(-dis[v], v));
			}
		}
	}
	return dis[n];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].PB(MP(b, c));
		adj[b].PB(MP(a, c));
	}
	LL res = dijkstra();
	if (res == inf) cout << "NO PATH EXISTS" << endl; 
	else cout << res << endl;
	return 0;
}
