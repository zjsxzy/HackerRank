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
    int ts;
    cin >> ts;
    while (ts--) {
        int n, k;
        cin >> n >> k;
        n--;
        int res;
        if (k == n / 2) {
            res = n;
        } else if (k >= n / 2) {
            res = 2 * (n - k);
        } else {
            res = 2 * (k + 1) - 1;
        }
        cout << res << endl;
    }
    return 0;
}