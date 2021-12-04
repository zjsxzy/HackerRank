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

int x[10005];
int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> n;
		int mn = 1000;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			mn = min(mn, x[i]);
		}
		int res = 1000000000;
		for (int m = max(0, mn - 4); m <= mn; m++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				int temp = x[i] - m;
				cnt += temp / 5 + (temp % 5) / 2 + (temp % 5) % 2;
			}
			res = min(res, cnt);
		}
		cout << res << endl;
	}
	return 0;
}

