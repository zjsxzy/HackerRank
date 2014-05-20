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

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		int a, b, n;
		scanf("%d%d%d", &n, &a, &b);
		set<int> res;
		for (int x = 0; x < n; x++) {
			res.insert(x * a + (n - x - 1) * b);
		}
		FOREACH(it, res) {
			printf("%d ", *it);
		}
		puts("");
	}
	return 0;
}

