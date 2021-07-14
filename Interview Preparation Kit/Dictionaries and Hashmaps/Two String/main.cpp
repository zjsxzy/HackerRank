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
int p;
cin >> p;
for (int i = 0; i < p; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    set<char> st;
    for (int j = 0; j < s1.size(); j++) {
        st.insert(s1[j]);
    }
    bool flag = false;
    for (int j = 0; j < s2.size(); j++) {
        if (st.find(s2[j]) != st.end()) {
            cout << "YES" << endl;
            flag = true;
            break;
        }
    }
    if (!flag) cout << "NO" << endl;
}
return 0;
}
