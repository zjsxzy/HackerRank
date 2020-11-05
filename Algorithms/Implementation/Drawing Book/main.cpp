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

int total_pages(int n) {
    return (n + 2) / 2;
}

int main() {
    int n, p;
    cin >> n >> p;
    int all = total_pages(n);
    int front = total_pages(p) - 1;
    int back = all - front - 1;
    cout << min(front, back) << endl;
    return 0;
}