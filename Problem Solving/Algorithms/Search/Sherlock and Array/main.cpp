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
    int ts, n;
    cin >> ts;
    while (ts--) {
        cin >> n;
        vector<int> arr(n), sum(n);
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i == 0) sum[i] = arr[i];
            else sum[i] = sum[i - 1] + arr[i];
            tot += arr[i];
        }
        if (n == 1) {
            cout << "YES" << endl;
        } else {
            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    if (tot - sum[i] == 0) {
                        cout << "YES" << endl;
                        flag = true;
                    }
                } else if (sum[i - 1] == tot - sum[i]) {
                    cout << "YES" << endl;
                    flag = true;
                }
            }
            if (!flag) cout << "NO" << endl;
        }
    }
    return 0;
}

