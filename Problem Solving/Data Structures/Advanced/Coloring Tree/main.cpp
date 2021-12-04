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
struct BinaryIndexTree {
	int N;
	int C[MAXN];
	
	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}
	
	int lowbit(int x) {
		return x & (-x);
	}
	
	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}
	
	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit;
struct query {
	int l, r, idx;
	query() {}
	query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
	bool operator < (const query &pt) const {
		return l < pt.l;
	}
}q[MAXN];
int N, M, root;
int tot;
int color[MAXN], father[MAXN];
int nxt[MAXN];
int seq[MAXN], in[MAXN], out[MAXN];
int ret[MAXN];
vector<int> adj[MAXN];

void dfs(int u) {
	seq[tot] = color[u];
	in[u] = tot++;
	FOREACH(it, adj[u]) {
		int v = *it;
		if (v == father[u]) continue;
		father[v] = u;
		dfs(v);
	}
	out[u] = tot;
}

int main() {
	scanf("%d%d%d", &N, &M, &root);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		adj[a].PB(b); adj[b].PB(a);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &color[i]);
	}
	root--;
	tot = 0;
	father[root] = -1;
	dfs(root);
	//for (int i = 0; i < N; i++) {
		//cout << seq[i] << " ";
	//}
	//cout << endl;
	for (int i = 0; i < N; i++) {
		q[i] = query(in[i], out[i], i);
		//cout << in[i] << " " << out[i] << " " << i << endl;
	}
	sort(q, q + N);
	map<int, int> mp;
	for (int i = N - 1; i >= 0; i--) {
		if (mp.find(seq[i]) == mp.end()) {
			nxt[i] = -1;
		} else {
			nxt[i] = mp[seq[i]];
		}
		mp[seq[i]] = i;
		//cout << seq[i] << " " << nxt[i] << endl;
	}
	bit.init(N);
	FOREACH(it, mp) {
		bit.add(it->second + 1, 1);
	}
	int l, r;
	int ptr = 0;
	// cout << bit.sum(4) - bit.sum(0) << endl;
	for (int i = 0; i < N; i++) {
		l = q[i].l;
		r = q[i].r;
		// cout << l << " " << r << endl;
		while (ptr < l) {
			if (nxt[ptr] != -1) {
				bit.add(nxt[ptr] + 1, 1);
			}
			ptr++;
		}
		ret[q[i].idx] = bit.sum(r) - bit.sum(l);
	}
	for (int i = 0; i < M; i++) {
		int u;
		scanf("%d", &u);
		u--;
		printf("%d\n", ret[u]);
	}
	return 0;
}

