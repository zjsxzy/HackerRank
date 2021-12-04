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
	int n, k;
	LL res = 0;
	cin >> n >> k;
	vector<LL> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	for (int i = 0; i < n; i++) {
		res += c[i] * (i / k + 1);
	}
	cout << res << endl;
	return 0;
}
