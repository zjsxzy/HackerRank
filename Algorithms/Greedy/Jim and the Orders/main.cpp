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

const int MAXN = 1005;
int n;
int order[MAXN], prep[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        cin >> order[i] >> prep[i];
        vec.push_back({order[i] + prep[i], i + 1});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        cout << vec[i].second << " ";
    }
    cout << endl;
    return 0;
}

