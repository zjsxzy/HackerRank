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

const int maxn = 1 << 15;
struct Tnode {
	int l, r;
	vector<int> p;
};
struct SegTree {
	Tnode T[maxn << 2];

	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}

	void build(int l, int r, int rt) {
		T[rt].l = l; T[rt].r = r;
		T[rt].p.clear();
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
	}

	void insert(int val, int pos, int rt) {
		T[rt].p.PB(pos);
		if (T[rt].l == T[rt].r) return;
		int mid = (T[rt].l + T[rt].r) >> 1;
		if (val <= mid) insert(val, pos, lson(rt));
		else insert(val, pos, rson(rt));
	}

	int query(int x, int from, int to, int rt) {
		if (T[rt].l == T[rt].r) return T[rt].l;
		int val = (T[rt].r - T[rt].l + 1) >> 1;
		if ((x & val) > 0) {
			if (exist(lson(rt), from, to)) {
				return query(x, from, to, lson(rt));
			} else {
				return query(x, from, to, rson(rt));
			}
		} else {
			if (exist(rson(rt), from, to)) {
				return query(x, from, to, rson(rt));
			} else {
				return query(x, from, to, lson(rt));
			}
		}
	}

	bool exist(int rt, int from, int to) {
		if (T[rt].p.size() == 0) return false;
		if (T[rt].p[0] > to) return false;
		if (T[rt].p[T[rt].p.size() - 1] < from) return false;
		int key = *lower_bound(T[rt].p.begin(), T[rt].p.end(), from);
		if (key <= to) return true;
		return false;
	}
}tree;

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		int n, q;
		scanf("%d%d", &n, &q);
		tree.build(0, maxn - 1, 1);
		for (int i = 0; i < n; i++) {
			int v;
			scanf("%d", &v);
			tree.insert(v, i + 1, 1);
		}
		while (q--) {
			int x, l, r;
			scanf("%d%d%d", &x, &l, &r);
			int res = tree.query(x, l, r, 1);
			printf("%d\n", res ^ x);
		}
	}
	return 0;
}
