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

int solve(int x) {
    int res = 0;
    int y = x;
    while (y) {
        int num = y % 10;
        if (num > 0) {
            if (x % num == 0) res++;
        }
        y /= 10;
    }
    return res;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}