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

void print_line(int x, int y) {
    for (int i = 0; i < x; i++) {
        cout << " ";
    }
    for (int i = 0; i < y; i++) {
        cout << "#";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        print_line(n - i, i);
    }
    return 0;
}

