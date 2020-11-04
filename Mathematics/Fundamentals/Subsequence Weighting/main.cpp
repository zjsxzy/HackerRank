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

const int maxn = 150000 + 50;
struct SegTree {
	LL mx[maxn << 1];
	void pushup(int rt) {
		mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	}
	void build() {
		memset(mx, 0, sizeof(mx));
	}
	void update(int pos, LL c, int l, int r, int rt) {
		if (l == r) {
			mx[rt] = max(mx[rt], c); return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, rt << 1);
		else update(pos, c, mid + 1, r, rt << 1 | 1);
		pushup(rt);
	}
	LL query(int L, int R, int l, int r, int rt) {
		if (L > R) return 0ll;
		if (L <= l && r <= R) {
			return mx[rt];
		}
		int mid = (l + r) >> 1;
		LL ret = 0;
		if (L <= mid) ret = max(ret, query(L, R, l, mid, rt << 1));
		if (R > mid) ret = max(ret, query(L, R, mid + 1, r, rt << 1 | 1));
		return ret;
	}
}tree;

int n;
int a[maxn], w[maxn], b[maxn];
LL dp[maxn];

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d", &n);
		int m = 0;
		map<int, int> mp;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) {
			if (mp.find(b[i]) == mp.end()) {
				mp[b[i]] = ++m;
			}
		}
		tree.build();
		for (int i = 1; i <= n; i++) {
			scanf("%d", w + i);
		}
		memset(dp, 0, sizeof(dp));
		LL res = 0;
		for (int i = 1; i <= n; i++) {
			LL temp = tree.query(1, mp[a[i]] - 1, 1, m, 1);
			dp[i] = temp + w[i];
			res = max(res, dp[i]);
			tree.update(mp[a[i]], dp[i], 1, m, 1);
		}
		cout << res << endl;
	}
	return 0;
}
