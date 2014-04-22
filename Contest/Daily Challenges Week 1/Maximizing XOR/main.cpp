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

int maxXor(int l, int r) {
	int ret = 0;
	for (int a = l; a <= r; a++) {
		for (int b = a; b <= r; b++) {
			ret = max(ret, a ^ b);
		}
	}
	return ret;
}

int main() {
	int l, r;
	scanf("%d%d", &l, &r);
	int ret = maxXor(l, r);
	printf("%d\n", ret);
	return 0;
}

