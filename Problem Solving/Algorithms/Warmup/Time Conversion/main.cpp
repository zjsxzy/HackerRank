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

int get_hour(string hour, string type) {
    int h = stoi(hour);
    if (type == "AM") {
        if (h == 12) return 0;
        else return h;
    } else {
        if (h == 12) return h;
        else return h + 12;
    }
}

int main() {
    string s;
    cin >> s;
    string type = s.substr(8, 2);
    int hour = get_hour(s.substr(0, 2), type);
    printf("%02d%s\n", hour, s.substr(2, 6).c_str());
    return 0;
}

