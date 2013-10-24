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

const int maxn = 100005;
const int inf = 2000000000;
struct edge {
	int u, v, w;
	edge() {}
	edge(int _u, int _v, int _w) {
		u = _u; v = _v; w = _w;
	}
	bool operator < (const edge &pt) const {
		return w < pt.w;
	}
};
vector<edge> e;
int n, m;
int dis[maxn], mk[maxn], p[maxn];
vector<pair<int, int> > adj[maxn];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
//		e.PB(edge(a, b, c));
		adj[a].PB(MP(b, c));
		adj[b].PB(MP(a, c));
	}
	int t1, t2;
	scanf("%d%d", &t1, &t2);
	if (t1 > t2) swap(t1, t2);
	/*
	//kruskal
	sort(e.begin(), e.end());
	for (int i = 1; i <= n; i++) p[i] = i;
	LL sum = 0;
	for (int i = 0; i < m; i++) {
		int pu = find(e[i].u), pv = find(e[i].v);
		if (pu != pv) {
			p[pu] = pv;
			sum += e[i].w;
		}
	}
	*/
	//prim
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
		mk[i] = false;
	}
	for (int i = 0; i < adj[1].size(); i++)
		dis[adj[1][i].first] = adj[1][i].second;
	dis[1] = 0;
	mk[1] = true;
	LL sum = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(MP(0, 1));
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		int u = cur.second;
		sum += dis[u];
		mk[u] = true;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, tmp = adj[u][i].second;
			if (!mk[v] && tmp < dis[v]) {
				dis[v] = tmp;
				pq.push(MP(-dis[v], v));
			}
		}
	}
	if (sum <= 0) cout << t1 << endl;
	else cout << t2 << endl;
	return 0;
}
