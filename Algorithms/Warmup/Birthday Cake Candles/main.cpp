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
    vector<int> arr;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > mx) mx = x;
        arr.push_back(x);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (mx == arr[i]) res++;
    }
    cout << res << endl;
    return 0;
}

