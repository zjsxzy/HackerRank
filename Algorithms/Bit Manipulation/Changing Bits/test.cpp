#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 100000 + 50;
int n, m, bitsum[maxn];
char str[2][maxn];
set<int> st;

struct BIT {
	int bit[maxn], n;
	void init(int _n) {
		n = _n;
	}
	void update(int x, int add) {
		x++;
		for (; x <= n; x += (x & -x))
			bit[x] += add;
	}
	int query(int x) {
		x++;
		int ret = 0;
		for (; x; x -= (x & -x))
			ret += bit[x];
		return ret;
	}
} bit;

char cmd[10];
int idx, x;
int main() {
	scanf("%d %d", &n, &m);
	scanf("%s %s", str[0], str[1]);
	reverse(str[0], str[0] + n);
	reverse(str[1], str[1] + n);
	bit.init(n);
	st.clear();

	for (int i = 0; i < n; i++) {
		bitsum[i] = str[1][i] - '0' + str[0][i] - '0';
		if (bitsum[i])
			bit.update(i, 1);
		if (bitsum[i] == 2)
			st.insert(i);
	}

	while (m--) {
		scanf("%s", cmd);
		if (cmd[0] == 's') {
			int i = cmd[4] - 'a';
			scanf("%d %d", &idx, &x);
			if (str[i][idx] < x + '0') {
				str[i][idx] = x + '0';
				bitsum[idx]++;
				if (bitsum[idx] == 1)
					bit.update(idx, 1);
				else if (bitsum[idx] == 2)
					st.insert(idx);
			} else if (str[i][idx] > x + '0') {
				str[i][idx] = x + '0';
				bitsum[idx]--;
				if (bitsum[idx] == 1)
					st.erase(idx);
				else if (bitsum[idx] == 0)
					bit.update(idx, -1);
			}
		} else {
			scanf("%d", &idx);
			int res = bitsum[idx];		
			set<int>::iterator it = st.lower_bound(idx);
			if (it != st.begin()) {
				--it;
				int j = *it;
				int k = bit.query(idx - 1) - bit.query(j - 1);
				if (k == idx - j)
					res++;
			}
			res &= 1;
			putchar('0' + res);
		}
	}
	puts("");
}

