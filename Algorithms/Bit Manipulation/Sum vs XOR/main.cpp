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

int bits(LL x) {
    int res = 0, mx = 0;
    for (int i = 0; i < 63; i++) {
        if ((x & (1LL << i)) > 0) {
            res++;
            mx = i;
        }
    }
    return mx + 1 - res;
}

int main() {
    LL n;
    cin >> n;
    if (n == 0) {
        cout << 1 << endl;
    } else {
        cout << (1LL << bits(n)) << endl;
    }
    return 0;
}