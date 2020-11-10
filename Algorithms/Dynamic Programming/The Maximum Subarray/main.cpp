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

void solve(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n);
    int res1 = -1e5, res2 = -1e5, mx = -1e5;
    for (int i = 0; i < n; i++) {
        mx = max(mx, arr[i]);
        if (arr[i] >= 0) {
            if (res2 < 0) res2 = 0;
            res2 += arr[i];
        }
        if (i == 0) dp[0] = arr[i];
        else {
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        }
        res1 = max(res1, dp[i]);
    }
    if (res2 == -1e5) res2 = mx;
    cout << res1 << " " << res2 << endl;
}
int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr);
    }
    return 0;
}

