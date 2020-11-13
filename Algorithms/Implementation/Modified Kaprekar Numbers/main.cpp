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

bool kaprekar(int x) {
    string s = to_string((LL)x * x);
    int d = s.size() / 2;
    int y = atoi(s.substr(0, d).c_str()) + atoi(s.substr(d, s.size() - d).c_str());
    return x == y;
}

int main() {
    int p, q;
    cin >> p >> q;
    bool flag = false;
    for (int i = p; i <= q; i++) {
        if (kaprekar(i)) {
            flag = true;
            cout << i << " ";
        }
    }
    if (!flag) {
        cout << "INVALID RANGE" << endl;
    }
    return 0;
}

