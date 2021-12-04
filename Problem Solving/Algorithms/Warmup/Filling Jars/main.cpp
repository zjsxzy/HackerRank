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

LL n, m;
int main() {
	cin >> n >> m;
	LL sum = 0;
	for (int i = 0; i < m; i++) {
		LL a, b, t;
		cin >> a >> b >> t;
		sum += (LL)t * (b - a + 1);
	}
	cout << sum / n << endl;
	return 0;
}

