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

string s, t;
int k;

string solve() {
    if (s.size() + t.size() < k) {
        return "Yes";
    }
    int i;
    for (; i < s.size() && i < t.size(); i++) {
        if (s[i] != t[i]) {
            break;
        }
    }
    int op = s.size() + t.size() - 2 * i;
    if (k == op || (k > op && (k - op) % 2 ==0)) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    cin >> s >> t >> k;
    cout << solve() << endl;
    return 0;
}