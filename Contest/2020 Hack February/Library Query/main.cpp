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

const int MAXN = 10000 + 5;
const int maxNode = MAXN * 20;
int N, Q, ans;
int tree[MAXN << 1], a[MAXN];
struct Treap {
	int root, treapCnt, key[maxNode], priority[maxNode], childs[maxNode][2], cnt[maxNode], size[maxNode];

	bool flag;

	void init() {
		root = 0;
		treapCnt = 1;
		priority[0] = INT_MAX;
		size[0] = 0;
		key[0] = -1;
	}

	void update(int x) {
		size[x] = size[childs[x][0]] + cnt[x] + size[childs[x][1]];
	}

	void rotate(int &x, int t) {
		int y = childs[x][t];
		childs[x][t] = childs[y][1 - t];
		childs[y][1 - t] = x;
		update(x);
		update(y);
		x = y;
	}

	void __insert(int &x, int k) {
		if (x) {
			if (key[x] == k) {
				cnt[x]++;
			} else {
				int t = key[x] < k;
				__insert(childs[x][t], k);
				if (priority[childs[x][t]] < priority[x]) {
					rotate(x, t);
				}
			}
		} else {
			x = treapCnt++;
			key[x] = k;
			cnt[x] = 1;
			priority[x] = rand();
			childs[x][0] = childs[x][1] = 0;
		}
		update(x);
	}

	void __erase(int &x, int k) {
		//if (!flag) return;
		if (key[x] == k) {
			if (cnt[x] > 1) {
				cnt[x]--;
			} else {
				if (childs[x][0] == 0 && childs[x][1] == 0) {
					x = 0;
					return;
				}
				int t = priority[childs[x][0]] > priority[childs[x][1]];
				rotate(x, t);
				__erase(x, k);
			}
		} else {
			if (childs[x][key[x] < k] == 0) {
				flag = false;
				return;
			}
			__erase(childs[x][key[x] < k], k);
		}
		update(x);
	}

	int __getKth(int &x, int k) {
		if (k <= size[childs[x][0]]) {
			return __getKth(childs[x][0], k);
		}
		k -= size[childs[x][0]] + cnt[x];
		if (k <= 0) {
			return key[x];
		}
		return __getKth(childs[x][1], k);
	}

	//插入元素的值
	void insert(int k) {
		__insert(root, k);
	}

	//删除元素的值
	bool erase(int k) {
		flag = true;
		__erase(root, k);
		return flag;
	}

	//返回treap中第K小元素
	int getKth(int k) {
		return __getKth(root, k);
	}

	//以x为根的子树中小于等于k的元素个数
	int select(int x, int k) {
		if (!x) return 0;
		if (k < key[x]) return select(childs[x][0], k);
		return size[childs[x][0]] + cnt[x] + select(childs[x][1], k);
	}
}treap;

int ID(int l, int r) {
	return (l + r) | (l != r); 
}
void treeAdd(int p, int x, int l, int r) {
	treap.__insert(tree[ID(l, r)], x);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (p <= mid) treeAdd(p, x, l, mid);
	else treeAdd(p, x, mid + 1, r);
}

void treeDel(int p, int x, int l, int r) {
	treap.__erase(tree[ID(l, r)], x);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (p <= mid) treeDel(p, x, l, mid);
	else treeDel(p, x, mid + 1, r);
}

void query(int L, int R, int k, int l, int r) {
	if (L <= l && r <= R) {
		ans += treap.select(tree[ID(l, r)], k);
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) query(L, R, k, l, mid);
	if (R > mid) query(L, R, k, mid + 1, r);
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &N);
		treap.init();
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
			treeAdd(i, a[i], 1, N);
		}
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
			int op;
			scanf("%d", &op);
			if (op == 0) {
				int l, r, k;
				scanf("%d%d%d", &l, &r, &k);
				int lo = 0, hi = 1000000000;
				while (lo < hi - 1) {
					int mid = (lo + hi) >> 1;
					ans = 0;
					query(l, r, mid, 1, N);
					if (ans < k) lo = mid;
					else hi = mid;
				}
				printf("%d\n", hi);
			} else {
				int x, y;
				scanf("%d%d", &x, &y);
				treeDel(x, a[x], 1, N);
				a[x] = y;
				treeAdd(x, a[x], 1, N);
			}
		}
	}
	return 0;
}

