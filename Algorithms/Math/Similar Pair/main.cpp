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
struct BinaryIndexTree {
	int N;
	int C[maxn];
	
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
/*
struct SegTree {

	int sum[maxn << 2];

	int lson(int rt) {return rt << 1; }
	int rson(int rt) {return rt << 1 | 1; }

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void build(int l, int r, int rt) {
		if (l == r) {
			sum[rt] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		int mid = (l + r) >> 1;
		int ret = 0;
		if (L <= mid) ret += query(L, R, l, mid, lson(rt));
		if (R > mid) ret += query(L, R, mid + 1, r, rson(rt));
		return ret;
	}

	void update(int pos, int c, int l, int r, int rt) {
		if (l == r) {
			sum[rt] += c;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, lson(rt));
		else update(pos, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}
}tree;
*/
int n, T;
LL res;
int deg[maxn];
vector<int> adj[maxn];

void dfs(int u) {
	res += bit.sum(min(n, u + T)) - bit.sum(max(1, u - T) - 1);
	bit.add(u, 1);
//	res += tree.query(max(1, u - T), min(n, u + T), 1, n, 1);
//	tree.update(u, 1, 1, n, 1);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs(v);
	}
	bit.add(u, -1);
//	tree.update(u, -1, 1, n, 1);
}

int main() {
	scanf("%d%d", &n, &T);
//	tree.build(1, n, 1);
	bit.init(n);
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].PB(b);
		deg[b]++;
	}
	int root = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) {
			root = i;
			break;
		}
	res = 0;
	dfs(root);
	cout << res << endl;
	return 0;
}
