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
const LL MOD = 1000000000 + 7;
int n;
vector<int> adj[MAXN];
int visited[MAXN];
LL cnt[MAXN];
void dfs(int u, int comp) {
	visited[u] = comp;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (visited[v] == 0) dfs(v, comp);
	}
}
LL quickpow(LL base, LL power) {
	LL ret = 1;
	for (; power; power >>= 1) {
		if (power & 1) ret = ret * base % MOD;
		base = base * base % MOD;
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b;
		char col;
		scanf("%d %d %c\n", &a, &b, &col);
		if (col == 'b') {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	memset(visited, 0, sizeof(visited));
	int comp = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] != 0) continue;
		comp++;
		dfs(i, comp);
	}
	for (int i = 1; i <= n; i++)
		cnt[visited[i]]++;
	LL sum = 0;
	for (int i = 1; i <= comp; i++) {
		sum += (LL)cnt[i];
	}
	LL ret = (sum * sum * sum) % MOD;
	for (int i = 1; i <= comp; i++) {
		ret -= (cnt[i] * cnt[i] * cnt[i]) % MOD;
		if (ret < 0) ret += MOD;
	}
	for (int i = 1; i <= comp; i++) {
		ret -= ((3 * cnt[i] * cnt[i]) * (sum - cnt[i])) % MOD;
		if (ret < 0) ret += MOD;
	}
	ret = ret * quickpow(6, MOD - 2) % MOD;
	cout << ret << endl;
	return 0;
}

