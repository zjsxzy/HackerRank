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
    int s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    int m, n;
    cin >> m >> n;
    int apple = 0, orange = 0;
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        if (s <= a + d && a + d <= t) apple++;
    }
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if (s <= b + d && b + d <= t) orange++;
    }
    cout << apple << endl;
    cout << orange << endl;
    return 0;
}

