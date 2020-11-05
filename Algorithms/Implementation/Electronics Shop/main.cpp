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
    int b, n, m;
    cin >> b >> n >> m;
    vector<int> keyboard(n), drives(m);
    for (int i = 0; i < n; i++) {
        cin >> keyboard[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> drives[i];
    }
    sort(drives.begin(), drives.end());
    int res = -1;
    for (int i = 0; i < n; i++) {
        int temp = b - keyboard[i];
        if (temp < 0) continue;
        auto it = upper_bound(drives.begin(), drives.end(), temp);
        if (it == drives.begin()) {
            continue;
        } else {
            it--;
        }
        // cout << keyboard[i] << " " << *it << endl;
        if (*it + keyboard[i] <= b) {
            res = max(res, *it + keyboard[i]);
        }
    }
    cout << res << endl;
    return 0;
}