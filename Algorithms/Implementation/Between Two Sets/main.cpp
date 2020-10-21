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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int, bool> fac;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1; a[i] * j <= 100; j++) {
            fac[a[i] * j] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (auto it : fac) {
        for (int i = 0; i < n; i++) {
            if (it.first % a[i] != 0) {
                fac[it.first] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            if (b[i] % it.first != 0) {
                fac[it.first] = false;
            }
        }
    }
    int res = 0;
    for (auto it : fac) {
        if (it.second) res++;
    }
    cout << res << endl;
    return 0;
}

