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
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> L(n), T(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> T[i];
        if (T[i] == 0) {
            res += L[i];
            L[i] = 0;
        }
    }
    sort(L.begin(), L.end());
    reverse(L.begin(), L.end());
    for (int i = 0; i < k; i++) {
        res += L[i];
    }
    for (int i = k; i < n; i++) {
        res -= L[i];
    }
    cout << res << endl;
    return 0;
}

