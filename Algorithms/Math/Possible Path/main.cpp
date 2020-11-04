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

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		LL a, b, x, y;
		scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
		puts(gcd(a, b) == gcd(x, y) ? "YES" : "NO");
	}
	return 0;
}

