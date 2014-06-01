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

const int MAXN = 200000 + 5;
const LL MOD = 1000000000 + 7;
char str[MAXN];
LL dp[MAXN];
void update(LL &a, LL b) {
	a = (a + b) % MOD;
}
int main() {
	scanf("%s", str);
	int n = strlen(str);
	dp[0] = str[0] - '0';
	for (int i = 1; i < n; i++) {
		update(dp[i], dp[i - 1] * 10);
		update(dp[i], (i + 1) * (str[i] - '0'));
	}
	LL ret = 0;
	for (int i = 0; i < n; i++) {
		update(ret, dp[i]);
	}
	cout << ret << endl;
	return 0;
}

