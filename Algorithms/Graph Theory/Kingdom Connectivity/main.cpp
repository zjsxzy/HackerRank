#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int mod = 1000000000;
const int maxn = 10005;
const int maxm = 100005;
struct Edge {
	int v, next;
}edge[2 * maxm], edge2[2 * maxm];
int N, M;
int low[maxn], dfn[maxn], cnt[maxn], id[maxn], vis[maxn], Stack[maxn];
int dp[maxn], reach[maxn], reach2[maxn], topo[maxn];
int num, Head[maxn], num2, Head2[maxn];
int Size, Top, Index, topcnt;

void addEdge(int u, int v)
{
	edge[num].v = v;
	edge[num].next = Head[u];
	Head[u] = num++;
}

void addEdge2(int u, int v)
{
	edge2[num2].v = v;
	edge2[num2].next = Head2[u];
	Head2[u] = num2++;
}

void Tarjan(int u)
{
	low[u] = dfn[u] = ++Index;
	Stack[++Top] = u;
	vis[u] = 1;
	for (int i = Head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (!dfn[v])
		{
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u])
	{
		Size++;
		for (; Stack[Top + 1] != u; --Top)
		{
			vis[Stack[Top]] = 0;
			id[Stack[Top]] = Size;
		}
	}
}

void dfs(int u)
{
	reach[u] = 1;
	for (int i = Head[u]; i != -1; i = edge[i].next)
		if (!reach[edge[i].v]) {
			dfs(edge[i].v);
		}
}

void dfs2(int u)
{
	reach2[u] = 1;
	for (int i = Head2[u]; i != -1; i = edge2[i].next)
		if (!reach2[edge2[i].v]) {
			dfs2(edge2[i].v);
		}
}

void topdfs(int u)
{
	vis[u] = true;
	for (int i = Head[u]; i != -1; i = edge[i].next)
		if (!vis[edge[i].v]) dfs(edge[i].v);
	topo[topcnt++] = u;
}

int main()
{	
//	freopen("in", "r", stdin);
	num = num2 = Top = Size = Index = 0;
	memset(Head, -1, sizeof(Head));
	memset(Head2, -1, sizeof(Head2));
	cin >> N >> M;
	for (; M--; ) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
		addEdge2(v, u);
	}
	for (int i = 1; i <= N; i++)
		if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= N; i++)
		cnt[id[i]]++;

	dfs(1);
	dfs2(N);
	if (!reach[N]) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++)
		if (reach[i] && reach2[i] && cnt[id[i]] > 1) {
			cout << "INFINITE PATHS" << endl;
			return 0;
		}

	num2 = 0;
	memset(Head2, -1, sizeof(Head2));
	for (int i = 1; i <= N; i++)
		for (int j = Head[i]; j != -1; j = edge[j].next)
			if (id[i] != id[edge[j].v]) {
				addEdge2(id[i], id[edge[j].v]);
			}
	memset(vis, 0, sizeof(vis));
	topcnt = 0;
	for (int i = 1; i <= Size; i++)
		if (!vis[i]) topdfs(i);
	reverse(topo, topo + Size);

	memset(dp, 0, sizeof(dp));
	dp[id[1]] = 1;
	for (int u = 0; u < topcnt; u++) {
		int idx = topo[u];
		if (dp[idx]) {
			for (int i = Head2[idx]; i != -1; i = edge2[i].next) {
				dp[edge2[i].v] += dp[idx];
				dp[edge2[i].v] %= mod;
			}
		}
	}
	cout << dp[id[N]] << endl;
	return 0;
}
