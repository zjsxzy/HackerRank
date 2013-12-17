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

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		int B, C;
		scanf("%d%d", &B, &C);
		vector<int> block(C + 1);
		vector<LL> dp(C + 1);
		for (int i = 1; i <= C; i++) {
			scanf("%d", &block[i]);
		}
		dp[0] = 1;
		for (int i = 0; i <= C; i++) {
			if (dp[i] == 0 || block[i] == 1) continue;
			for (int j = 1; j <= B && i + j <= C; j++) {
				if (block[i + j] == 1) continue;
				dp[i + j] += dp[i];
			}
		}
		LL ret = 0;
		for (int i = C; i + B > C && i >= 1; i--)
			ret += dp[i];
		cout << ret << endl;
	}
	return 0;
}

