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
        int sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
        }
        if (sum % 3 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}