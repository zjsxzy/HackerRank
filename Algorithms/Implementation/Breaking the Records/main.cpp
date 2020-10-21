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
    int mn, mx;
    int high = 0, low = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            mn = x;
            mx = x;
        } else {
            if (x < mn) {
                low++;
                mn = x;
            }
            if (x > mx) {
                high++;
                mx = x;
            }
        }
    }
    cout << high << " " << low << endl;
    return 0;
}

