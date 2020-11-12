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

const int MAXN = 250;
int n, m;
int c[MAXN];

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c + n);
    vector<LL> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= m; j++) {
            dp[j] += dp[j - c[i]];
        }
    }
    cout << dp[m] << endl;
    return 0;
}