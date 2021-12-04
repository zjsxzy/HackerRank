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
    int n;
    cin >> n;
    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    int a, b, c;
    LL p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (sticks[i] + sticks[j] > sticks[k]) {
                    LL temp = (LL)sticks[i] + sticks[j] + sticks[k];
                    if (temp >= p) {
                        p = temp;
                        a = sticks[i]; b = sticks[j]; c = sticks[k];
                    }
                }
            }
        }
    }
    if (p == 0) cout << -1 << endl;
    else cout << a << " " << b << " " << c << endl;
    return 0;
}

