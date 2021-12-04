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
    vector<int> arr(5);
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < 4; i++) {
        sum1 += arr[i];
        sum2 += arr[5 - i - 1];
    }
    cout << sum1 << " " << sum2 << endl;
    return 0;
}

