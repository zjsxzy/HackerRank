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

const int MAXN = 1000005;
int n, m;
vector<int> adj[MAXN];
int flag[MAXN], deg[MAXN];
priority_queue<int> pq;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	memset(flag, 0, sizeof(flag));
	memset(deg, 0, sizeof(deg));
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &n);
		int p;
		scanf("%d", &p); flag[p] = 1;
		for (int j = 1; j < n; j++) {
			int q;
			scanf("%d", &q); flag[q] = 1;
			adj[p].push_back(q);
			deg[q]++;
			p = q;
		}
	}
	while (!pq.empty()) pq.pop();
	for (int i = 1; i < MAXN; i++) {
		if (flag[i] && deg[i] == 0) {
			pq.push(-i);
		}
	}
	vector<int> ans;
	while (!pq.empty()) {
		int u = -pq.top(); pq.pop();
		ans.push_back(u);
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			deg[v]--;
			if (deg[v] == 0) {
				pq.push(-v);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}

