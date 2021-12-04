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

vector<int> sq;
void init() {
    for (int i = 1; i <= 32000; i++) {
        sq.push_back(i * i);
    }
}

int main() {
    init();
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        auto l = lower_bound(sq.begin(), sq.end(), a) - sq.begin();
        auto r = upper_bound(sq.begin(), sq.end(), b) - sq.begin();
        cout << r - l << endl;
    }
    return 0;
}

