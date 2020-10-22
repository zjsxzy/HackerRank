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

const int MAXN = 105;
int dp[MAXN];
int mv[3] = {2, 3, 5};

void pre() {
    dp[0] = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - mv[j] >= 0 && !dp[i - mv[j]]) {
                dp[i] = 1;
            }
        }
    }
}

int main() {
    pre();
    int ts;
    cin >> ts;
    while (ts--) {
        int n;
        cin >> n;
        if (dp[n]) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}

