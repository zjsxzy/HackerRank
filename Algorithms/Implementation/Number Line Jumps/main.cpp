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
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if (v1 == v2) {
        if (x1 == x2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if ((x2 - x1) % (v1 - v2) == 0 && (x2 - x1) * (v1 - v2) > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

