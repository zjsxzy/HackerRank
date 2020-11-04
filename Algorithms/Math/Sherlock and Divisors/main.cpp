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
        int n;
        cin >> n;
        int res = 0;
        for (int i = 1; i <= (int)sqrt(n); i++) {
            if (n % i == 0) {
                if (i % 2 == 0) res++;
                if (i != n / i && n / i % 2 == 0) res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}

