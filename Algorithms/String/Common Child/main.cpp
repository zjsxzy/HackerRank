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

const int MAXN = 5000 + 5;
string A, B;
int dp[MAXN][MAXN];

int main() {
	while (cin >> A >> B) {
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= A.size(); i++) {
			for (int j = 1; j <= B.size(); j++) {
				if (A[i - 1] == B[j - 1]) {
					if (i > 0 && j > 0) dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
					if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[A.size()][B.size()] << endl;
	}
	return 0;
}

