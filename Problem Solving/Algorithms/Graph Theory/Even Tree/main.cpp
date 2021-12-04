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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int maxn = 105;
int n, m;
vector<int> adj[maxn];
int res;
int sum[maxn];

void dfs(int u, int fa) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != fa) {
			dfs(v, u);
			if (sum[v] % 2 == 0) {
				res++;
			} else {
				sum[u] += sum[v];
			}
		}
	}
	sum[u]++;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].PB(b);
		adj[b].PB(a);
	}
	res = 0;
	dfs(1, 0);
	printf("%d\n", res);
	return 0;
}
