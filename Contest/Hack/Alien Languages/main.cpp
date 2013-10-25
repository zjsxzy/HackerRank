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
typedef long long LL;

const int MAX_LEN = 500005;
const int MAXN = 100005;
const LL MOD = 100000007;
int n, m;
LL dp[MAX_LEN], f[20][MAXN], g[20];

int main(int argc, char const *argv[])
{
	int Test;
	cin >> Test;
	while (Test--) {
		cin >> n >> m;
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		memset(dp, 0, sizeof(dp));
		int mid = n >> 1;
		for (int i = 0; i <= mid; i++)
			f[0][i] = 1;

		int len = 0;
		for (int i = 1, p = 1; i <= m && p <= mid; i++, p <<= 1) {
			for (int j = p; j <= mid; j++) {
				f[i][j] = (f[i][j - 1] + f[i - 1][j >> 1]) % MOD;
			}
			len = i;
		}

		for (int i = 1; i <= len + 1; i++) {
			for (int j = mid + 1; j <= n; j++) {
				g[i] = (g[i] + f[i - 1][j >> 1]) % MOD;
			}
		}

		dp[0] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= len + 1; j++) {
				if (i - j < 0) continue;
				dp[i] += dp[i - j] * g[j];
				dp[i] %= MOD;
			}
		}

		cout << dp[m] << endl;
	}
	return 0;
}
