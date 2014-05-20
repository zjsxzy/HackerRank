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
struct SegTree {
	int sum[maxn << 2];
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
	void update(int pos, int c, int l, int r, int rt) {
		if (l == r) {
			sum[rt] += c;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, lson(rt));
		else update(pos, c, mid + 1, r, rson(rt));
		pushup(rt);
	}
	int query(int from, int to, int l, int r, int rt) {
		if (from <= l && r <= to) {
			return sum[rt];
		}
		int mid = (l + r) >> 1;
		int res = 0;
		if (from <= mid) res += query(from, to, l, mid, lson(rt));
		if (to > mid) res += query(from, to, mid + 1, r, rson(rt));
		return res;
	}
}tree;

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
}T;

int bit[maxn];
char A[maxn], B[maxn];
int main() {
	int n, q;
	while (~scanf("%d%d", &n, &q)) {
		set<int> st;
		tree.build(0, n, 1);
		//T.init(n);
		scanf("%s %s", A, B);
		reverse(A, A + n); 
		reverse(B, B + n);
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			bit[i] = A[i] - '0' + B[i] - '0';
			if (bit[i]) {
				tree.update(i + 1, 1, 0, n, 1);
				//T.add(i + 1, 1);
			}
			if (bit[i] == 2) st.insert(i);
		}
		while (q--) {
			char op[10];
			scanf("%s", op);
			int size = strlen(op);
			if (op[0] == 's') {
				int idx, x;
				scanf("%d%d", &idx, &x);
				if (op[size - 1] == 'a') {
					if (A[idx] - '0' < x) {
						A[idx] = '0' + x;
						bit[idx]++;
						if (bit[idx] == 1) {
							tree.update(idx + 1, 1, 0, n, 1);
							//T.add(idx + 1, 1);
						}
						if (bit[idx] == 2) st.insert(idx);
					} else if (A[idx] - '0' > x) {
						A[idx] = '0' + x;
						bit[idx]--;
						if (bit[idx] == 0) {
							tree.update(idx + 1, -1, 0, n, 1);
							//T.add(idx + 1, -1);
						}
						if (bit[idx] == 1) st.erase(idx);
					}
				} else {
					if (B[idx] - '0' < x) {
						B[idx] = '0' + x;
						bit[idx]++;
						if (bit[idx] == 1) {
							//T.add(idx + 1, 1);
							tree.update(idx + 1, 1, 0, n, 1);
						}
						if (bit[idx] == 2) st.insert(idx);
					} else if (B[idx] - '0' > x) {
						B[idx] = '0' + x;
						bit[idx]--;
						if (bit[idx] == 0) {
							//T.add(idx + 1, -1);
							tree.update(idx + 1, -1, 0, n, 1);
						}
						if (bit[idx] == 1) st.erase(idx);
					}
				}
			} else {
				int idx;
				scanf("%d", &idx);
				int res = bit[idx];
				set<int>::iterator it = st.lower_bound(idx);
				if (it != st.begin()) {
					it--;
					int pre = *it;
					int num1 = tree.query(pre + 1, idx, 0, n, 1);
					//int num1 = T.sum(idx) - T.sum(pre);
					if (num1 == idx - pre) {
						res++;	
					}
				}
				res &= 1;
				printf("%d", res);
			}
		}
		cout << endl;
	}
	return 0;
}
