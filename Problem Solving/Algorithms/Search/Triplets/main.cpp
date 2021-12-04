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

struct node {
	int val, idx;
	bool operator < (const node &pt) const {
		return val == pt.val ? idx < pt.idx : val < pt.val;
	}
}a[maxn];
bool cmp(const node &A, const node &B) {
	return A.idx < B.idx;
}
int n;
int ll[maxn], rr[maxn];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].val; a[i].idx = i;
	}
	sort(a, a + n);
	map<int, int> mp, pre;
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (mp.find(a[i].val) == mp.end()) {
			mp[a[i].val] = ++m;
		}
	}

	set<int> st;
	bit.init(m);
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		int idx = mp[a[i].val];
		int leftSum = bit.sum(idx - 1);
		ll[i] = leftSum - pre[idx];
		if (st.find(idx) == st.end()) {
			bit.add(idx, 1);
			st.insert(idx);
		}
		pre[idx] = leftSum;
	}

	bit.init(m);
	pre.clear();
	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		int idx = m - mp[a[i].val] + 1;
		int rightSum = bit.sum(idx - 1);
		rr[i] = rightSum - pre[idx];
		if (st.find(idx) == st.end()) {
			bit.add(idx, 1);
			st.insert(idx);
		}
	}

	LL res = 0;
	for (int i = 0; i < n; i++) {
		res += (LL)ll[i] * rr[i];
	}
	cout << res << endl;
	return 0;
}
