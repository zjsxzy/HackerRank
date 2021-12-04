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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int, int> pos;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
        pq.push(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        auto it = pq.top(); pq.pop(); 
        if (pos[it] != i) {
            pos[arr[i]] = pos[it];
            arr[pos[it]] = arr[i];
            arr[i] = it;
            k--;
            if (k == 0) break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}