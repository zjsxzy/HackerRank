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

const int MAXN = 100005;
const int MOD = 1000000007;
int n, k, x;
LL dp[MAXN][2];

int main() {
    cin >> n >> k >> x;
    if (x == 1) {
        dp[0][0] = 0;
        dp[0][1] = 1;
    } else {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    for (int i = 1; i < n - 1; i++) {
        dp[i][0] = dp[i - 1][1] * (k - 1) % MOD;
        dp[i][0] = (dp[i][0] + dp[i - 1][0] * (k - 2)) % MOD;
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[n - 2][0] << endl;
    return 0;
}