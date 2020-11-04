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

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[p[i]] = i;
    }
    // for (int i = 1; i <= n; i++) {
        // cout << f[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << f[f[i]] << endl;
    }
    return 0;
}