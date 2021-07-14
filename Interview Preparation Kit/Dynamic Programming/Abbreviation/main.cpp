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

const int MAXN = 1005;
bool dp[MAXN][MAXN];

void solve(string &s, string &t) {
    int n = s.size(), m = t.size();
    if (n < m) {
        cout << "NO" << endl;
        return;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        char a = s[i - 1];
        if (islower(a)) {
            dp[i][0] = true;
        } else {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(m, i); j++) {
            char a = s[i - 1], b = t[j - 1];
            if (islower(a)) {
                dp[i][j] = dp[i - 1][j];
            }
            if (toupper(a) == b) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
            }
        }
    }
    if (dp[n][m]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        string s, t;
        cin >> s >> t;
        solve(s, t);
    }
    return 0;
}