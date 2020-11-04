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

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dx = abs(x1 - x2), dy = abs(y1 - y2);
        cout << gcd(dx, dy) - 1 << endl;
    }
    return 0;
}

