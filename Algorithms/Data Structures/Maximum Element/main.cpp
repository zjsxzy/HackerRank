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

int n;

int main() {
    cin >> n;
    stack<int> st;
    multiset<int> se;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            st.push(x);
            se.insert(x);
        } else if (t == 2) {
            int x = st.top(); st.pop();
            se.erase(se.find(x));
        } else if (t == 3) {
            cout << *se.rbegin() << endl;
        }
    }
    return 0;
}

