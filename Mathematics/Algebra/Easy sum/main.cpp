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
		LL n, m;
		cin >> n >> m;
		LL div = n / m, r = n % m;
		LL ret = div * m * (m - 1) / 2 + r * (r + 1) / 2;
		cout << ret << endl;
	}
	return 0;
}

