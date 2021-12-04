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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int prob = 0;
    int page = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            if (j == page) {
                // cout << i + 1 << " " << j << " " << endl;
                res++;
            }
            prob++;
            if (prob == k) {
                page++;
                prob = 0;
            }
        }
        if (prob > 0) {
            page++;
            prob = 0;
        }
    }
    cout << res << endl;
    return 0;
}

