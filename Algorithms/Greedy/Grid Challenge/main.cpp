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

void solve(int n) {
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    for (int j = 0; j < n; j++) {
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (s[i][j] < s[i - 1][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}