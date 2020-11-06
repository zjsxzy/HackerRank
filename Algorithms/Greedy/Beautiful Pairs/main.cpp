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
#include <cassert>
#include <climits>
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
    int n;
    cin >> n;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    int res = 0;
    for (auto x : a) {
        if (b.find(x.first) != b.end()) {
            res += min(b[x.first], x.second);
        }
    }
    if (res == n) cout << res - 1 << endl;
    else cout << res + 1 << endl;
    return 0;
}