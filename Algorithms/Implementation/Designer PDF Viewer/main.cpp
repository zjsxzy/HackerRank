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
    vector<int> h(26);
    for (int i = 0; i < 26; i++) {
        cin >> h[i];
    }
    string s;
    cin >> s;
    int tall = 0;
    for (int i = 0; i < s.size(); i++) {
        if (h[s[i] - 'a'] > tall) {
            tall = h[s[i] - 'a'];
        }
    }
    cout << tall * s.size() << endl;
    return 0;
}