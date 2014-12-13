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
const int MAXK = 200 + 5;
const LL INF = 1LL << 60;
int n, K, ind;
int weight[MAXN], First[MAXN], Last[MAXN], order[MAXN];
vector<int> adj[MAXN];
LL dp[MAXN][MAXK];

void dfs(int u, int father) {
	First[u] = ++ind;
	order[ind] = u;
	for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
		if (*it != father)
			dfs(*it, u);
	}
	Last[u] = ind;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++)
		scanf("%d", weight + i);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ind = 0;
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= K; j++)
			dp[i][j] = -INF; 
	dp[1][0] = 0;
	for (int i = 1; i <= n; i++) {
		int node = order[i];
		for (int j = 0; j <= K; j++) {
			if (dp[i][j] == INF) continue;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + weight[node]);
			if (j + 1 <= K) {
				dp[Last[node] + 1][j + 1] = max(dp[Last[node] + 1][j + 1], dp[i][j]);
			}
		}
	}
	LL ret = 0;
	for (int j = 0; j <= K; j++)
		ret = max(ret, dp[n + 1][j]);
	cout << ret << endl;
	return 0;
}

