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
    int d1, m1, y1, d2, m2, y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;
    int fine;
    if ((d2 >= d1 && m2 >= m1 && y2 >= y1) || (m2 > m1 && y2 >= y1) || (y2 > y1)) {
        fine = 0;
    } else if ((d2 < d1) && (m2 == m1) && (y2 >= y1)) {
        fine = 15 * abs(d2 - d1);
    } else if (m2 < m1 && y2 == y1) {
        fine = 500 * abs(m2 - m1);
    } else {
        fine = 10000;
    }
    cout << fine << endl;
    return 0;
}