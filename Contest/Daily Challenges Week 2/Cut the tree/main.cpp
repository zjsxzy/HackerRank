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
int n;
vector<int> adj[MAXN];
int weight[MAXN], subw[MAXN];
int sum;

void dfs(int u, int fa) {
	for (int i = 0, v; i < adj[u].size(); i++) {
		if ((v = adj[u][i]) == fa) continue;
		dfs(v, u);
		subw[u] += subw[v];
	}
	subw[u] += weight[u];
}

int main() {
	scanf("%d", &n);
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", weight + i);
		sum += weight[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	dfs(0, -1);
	int ret = sum;
	for (int i = 1; i < n; i++) {
		ret = min(ret, abs(sum - subw[i] - subw[i]));
	}
	printf("%d\n", ret);
	return 0;
}

