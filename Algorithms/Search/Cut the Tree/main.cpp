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

const int MAXN = 100000 + 5;
int n, ret, tot;
int val[MAXN], sum[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int fa) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		dfs(v, u);
		sum[u] += sum[v];
	}
	sum[u] += val[u];
	ret = min(ret, abs(tot - 2 * sum[u]));
}

int main() {
	scanf("%d", &n);
	tot = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", val + i);
		tot += val[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	ret = 0x3f3f3f3f;
	dfs(0, -1);
	printf("%d\n", ret);
	return 0;
}

