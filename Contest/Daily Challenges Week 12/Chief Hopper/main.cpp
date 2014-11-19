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
int n;
int h[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		if ((ret + h[i]) % 2 == 1) ret = (ret + h[i] + 1) >> 1;
		else ret = (ret + h[i]) >> 1;
	}
	printf("%d\n", ret);
	return 0;
}

