#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 20;
struct Task {
	int m, d, id, s;
}t[maxn];
struct Node {
	int l, r, m, diff;
	Node() {l = r = m = diff = 0;}
	Node(int ll, int rr) {
		l = ll; r = rr;
		m = diff = 0;
	}
}node[maxn << 2];
int n;
int rpos[maxn], ans[maxn];

bool cmp(Task A, Task B) {
	if (A.d == B.d) return A.id < B.id;
	return A.d < B.d;
}

inline int lson(int x) {
	return x << 1;
}

inline int rson(int x) {
	return x << 1 | 1;
}

inline void pushUp(int rt) {
	node[rt].m = max(node[lson(rt)].m, node[rson(rt)].m);
}

inline void pushDown(int rt) {
	if (node[rt].diff) {
		node[lson(rt)].m += node[rt].diff;
		node[rson(rt)].m += node[rt].diff;
		node[lson(rt)].diff += node[rt].diff;
		node[rson(rt)].diff += node[rt].diff;
		node[rt].diff = 0;
	}
}

inline void build(int rt, int l, int r) {
	node[rt] = Node(l, r);
	if (l == r) {
		node[rt].m = t[r].s;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson(rt), l, mid);
	build(rson(rt), mid + 1, r);
	pushUp(rt);
}

inline void zero(int rt, int pos) {
	if (node[rt].l == node[rt].r) {
		node[rt].m = node[rt].diff = 0;
		return;
	}
	pushDown(rt);
	int mid = (node[rt].l + node[rt].r) >> 1;
	if (pos <= mid) zero(lson(rt), pos);
	else zero(rson(rt), pos);
	pushUp(rt);
}

inline void update(int rt, int L, int R, int diff) {
	if (L <= node[rt].l && node[rt].r <= R) {
		node[rt].diff += diff;
		node[rt].m += diff;
		return;
	}
	pushDown(rt);
	int mid = (node[rt].l + node[rt].r) >> 1;
	if (L <= mid) update(lson(rt), L, R, diff);
	if (R > mid) update(rson(rt), L, R, diff);
	pushUp(rt);
}

void Print(int rt) {
	printf("%d %d %d %d\n",node[rt].l, node[rt].r, node[rt].m, node[rt].diff);
	if (node[rt].l == node[rt].r) return;
	Print(lson(rt));
	Print(rson(rt));
}

int main() {
//	freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &t[i].d, &t[i].m);
			t[i].id = i;
		}
		sort(t, t + n, cmp);
		int total_time = 0;
		for (int i = 0; i < n; i++) {
			rpos[t[i].id] = i;
			total_time += t[i].m;
			t[i].s = total_time - t[i].d;
		}
		build(1, 0, n - 1);
		for (int i = n - 1; i >= 0; i--) {
			ans[i] = node[1].m;
			zero(1, rpos[i]);
			update(1, rpos[i], n - 1, -t[rpos[i]].m);
		}
		for (int i = 0; i < n; i++)
			printf("%d\n", max(0, ans[i]));
	}
	return 0;
}
