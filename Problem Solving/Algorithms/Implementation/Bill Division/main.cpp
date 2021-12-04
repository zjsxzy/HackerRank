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
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i != k) sum += x;
    }
    int share;
    cin >> share;
    int res = share - sum / 2;
    if (res == 0) cout << "Bon Appetit" << endl;
    else cout << res << endl;
    return 0;
}

