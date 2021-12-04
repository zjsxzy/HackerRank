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

string construct(int x, int y) {
    string res = "";
    for (int i = 0; i < x; i++) {
        res += "5";
    }
    for (int i = 0; i < y; i++) {
        res += "3";
    }
    return res;
}

string solve(int n) {
    if (n % 3 == 0) {
        return construct(n, 0);
    } else {
        int resx = -1;
        for (int x = 0; x < n; x += 3) {
            if ((n - x) % 5 == 0) {
                resx = x;
            }
        }
        if (resx != -1) {
            return construct(resx, n - resx);
        }
        else {
            return "-1";
        }
    }
}

int main() {
    int ts, n;
    cin >> ts;
    while (ts--) {
        cin >> n;
        string res = solve(n);
        cout << res << endl;
    }
    return 0;
}

