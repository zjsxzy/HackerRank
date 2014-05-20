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

const int maxn = 200005;
const LL mod = 1000000007;
struct SegTree {
	LL sum[maxn << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushup(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}
	void build(int l, int r, int rt) {
		sum[rt] = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
	}
	void update(int pos, LL c, int l, int r, int rt) {
		if (l == r) {
			sum[rt] += c;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, lson(rt));
		else update(pos, c, mid + 1, r, rson(rt));
		pushup(rt);
	}
	LL query(int from, int to, int l, int r, int rt) {
		if (from <= l && r <= to) {
			return sum[rt];
		}
		int mid = (l + r) >> 1;
		LL res = 0;
		if (from <= mid) res += query(from, to, l, mid, lson(rt));
		if (to > mid) res += query(from, to, mid + 1, r, rson(rt));
		return res;
	}
}tree, tr;

struct City {
	int x, p;
	int idx;
	bool operator < (const City &pt) const {
		return p < pt.p;
	}
} city[maxn];

bool cmp(const City &a, const City &b) {
	return a.x < b.x;
}

int n;

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &city[i].x);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &city[i].p);
		}

		sort(city, city + n, cmp);
		for (int i = 0; i < n; i++) {
			city[i].idx = i + 1;
		}
		tree.build(1, n, 1);
		tr.build(1, n, 1);

		sort(city, city + n);

		LL res = 0;
		for (int i = 0; i < n; i++) {
			LL suml = tree.query(1, city[i].idx, 1, n, 1);
			LL sumr = tree.query(city[i].idx, n, 1, n, 1);
			LL numl = tr.query(1, city[i].idx, 1, n, 1);
			LL numr = tr.query(city[i].idx, n, 1, n, 1);
			res += ((numl * city[i].x - suml) + (sumr - numr * city[i].x)) * city[i].p;
			res %= mod;
			tree.update(city[i].idx, city[i].x, 1, n, 1);
			tr.update(city[i].idx, 1, 1, n, 1);
		}
		cout << res << endl;
	}
	return 0;
}
