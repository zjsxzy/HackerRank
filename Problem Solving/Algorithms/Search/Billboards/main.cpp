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
const LL inf = 1LL << 60;
struct SegTree {
	LL mx[maxn << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushup(int rt) {
		mx[rt] = max(mx[lson(rt)], mx[rson(rt)]);
	}
	void build(int l, int r, int rt) {
		mx[rt] = -inf;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
	}
	void update(int pos, LL c, int l, int r, int rt) {
		if (l == r) {
			mx[rt] = c;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, lson(rt));
		else update(pos, c, mid + 1, r, rson(rt));
		pushup(rt);
	}
	LL query(int L, int R, int l, int r, int rt) {
		if (L > R) return 0;
		if (L <= l && r <= R) {
			return mx[rt];
		}
		int mid = (l + r) >> 1;
		LL ret = -inf;
		if (L <= mid) ret = max(ret, query(L, R, l, mid, lson(rt)));
		if (R > mid) ret = max(ret, query(L, R, mid + 1, r, rson(rt)));
		return ret;
	}
}tree;
int n, K;
LL dp[maxn][2];
LL val[maxn], sum[maxn];

int main() {
	sum[0] = 0;
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
		sum[i] = sum[i - 1] + val[i];
	}
	tree.build(0, n, 1);
	tree.update(0, 0, 0, n, 1);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		LL mx = tree.query(max(0, i - K), i - 1, 0, n, 1);
		LL temp = mx + sum[i - 1];
		dp[i][1] = temp + val[i];
		tree.update(i, dp[i][0] - sum[i], 0, n, 1);
		/*
		for (int j = 1; j <= K && i - j > 0; j++) {
			int temp = dp[i - j][0] + sum[i - 1] - sum[i - j];
			if (dp[i][1] < temp)
				dp[i][1] = temp;
		}
		dp[i][1] += val[i];
		*/
	}
	LL res = max(dp[n][0], dp[n][1]);
	cout << res << endl;
	return 0;
}
