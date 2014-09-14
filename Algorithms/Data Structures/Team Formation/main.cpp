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
#include <cassert>
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

const int MAXN = 100000 + 5;
int a[MAXN];
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		map<int, multiset<int> > q;
		for (int i = 0; i < n; i++) {
			int val = a[i];
			map<int, multiset<int> >::iterator it = q.find(val - 1);
			if (it != q.end()) {
				multiset<int>::iterator iter = it->second.begin();
				int size = *iter;
				it->second.erase(iter);
				q[val].insert(size + 1);
				if (it->second.empty()) {
					q.erase(val - 1);
				}
			} else {
				q[val].insert(1);
			}
		}
		int res = INT_MAX;
		FOREACH(it, q) {
			res = min(res, *(it->second.begin()));
		}
		printf("%d\n", res == INT_MAX ? 0 : res);
	}
	return 0;
}

