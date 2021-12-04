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
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int x = arr[i] + d, y = arr[i] + d + d;
        if (cnt.find(x) != cnt.end()) {
            if (cnt.find(y) != cnt.end()) {
                res += cnt[x] * cnt[y];
            }
        }
    }
    cout << res << endl;
    return 0;
}

