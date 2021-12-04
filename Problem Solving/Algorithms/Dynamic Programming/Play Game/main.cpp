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
int a[MAXN];
LL sum[MAXN], dp[MAXN];

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		for (int i = n - 1; i >= 0; i--) {
			scanf("%d", a + i);
		}
		for (int i = 0; i < n; i++) {
			sum[i] = i == 0 ? a[i] : sum[i - 1] + a[i];
		}
		dp[0] = (LL)a[0];
		dp[1] = (LL)a[0] + a[1];
		dp[2] = (LL)a[0] + a[1] + a[2];
		for (int i = 3; i < n; i++) {
			dp[i] = 0;
			LL temp = sum[i - 1] - dp[i - 1] + a[i];
			if (temp > dp[i]) dp[i] = temp;
			temp = sum[i - 2] - dp[i - 2] + a[i] + a[i - 1];
			if (temp > dp[i]) dp[i] = temp;
			temp = sum[i - 3] - dp[i - 3] + a[i] + a[i - 1] + a[i - 2];
			if (temp > dp[i]) dp[i] = temp;
		}
		cout << dp[n - 1] << endl;
	}
	return 0;
}

