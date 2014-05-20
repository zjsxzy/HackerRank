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

const LL mod = 1000000007;
int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> x(n), D(n);
		LL res = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &D[i]);
		}

	}
	return 0;
}
