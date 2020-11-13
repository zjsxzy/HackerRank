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

int solve(string s, string t) {
    map<char, int> cnt;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]]++;
    }
    int common = 0;
    for (int i = 0; i < t.size(); i++) {
        if (cnt.find(t[i]) != cnt.end()) {
            if (cnt[t[i]] > 0) {
                common++;
                cnt[t[i]]--;
            }
        }
    }
    return s.size() + t.size() - common * 2;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s.size() % 2 != 0) {
            cout << -1 << endl;
        } else {
            int d = s.size() / 2;
            string a = s.substr(0, d), b = s.substr(d, d);
            cout << solve(a, b) / 2 << endl;
        }
    }
    return 0;
}

