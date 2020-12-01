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
typedef long long LL;

int even[5] = {1, 3, 5, 7, 9};
int odd[5] = {0, 2, 4, 6, 8};

int main() {
    int r, c;
    cin >> r >> c;
    int x = (r - 1) / 2;
    if (x > 0) cout << x;
    if (r & 1) cout << odd[c - 1] << endl;
    else cout << even[c - 1] << endl;
    return 0;
}

