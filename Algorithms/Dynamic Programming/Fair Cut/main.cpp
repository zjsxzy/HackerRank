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

const int MAXN = 3005;
const LL INF = 1e18;
int n, k;
LL a[MAXN];
LL dp[MAXN][MAXN];

void solve() {
    if (k > n / 2) {
        k = n - k;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    dp[1][0] = -a[1] * k; // give a[1] to lu
    dp[1][1] = -a[1] * (n - k); // give a[1] to li
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {

            // give a[i] to lu
            LL lu = i - 1 - j, li = j;
            if (lu >= 0 && lu < n - k && li >= 0 && li <= k) {
                LL temp = a[i] * li - a[i] * (k - li);
                if (dp[i - 1][j] + temp < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j] + temp;
                }
            }

            // give a[i] to Li
            lu = i - j, li = j - 1;
            if (lu >= 0 && lu <= n - k && li >= 0 && li < k) {
                LL temp = a[i] * lu - a[i] * ((n - k) - lu);
                if (dp[i - 1][j - 1] + temp < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + temp;
                }
            }
        }
    }
    cout << dp[n][k] << endl;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    solve();
    return 0;
}

