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

const int MAXN = 1000000 + 5;
int n, k;
int a[MAXN];

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &k);
		int sum = 0;
		map<int, int> mp;
		mp[0]++;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			sum = (sum + a[i]) % k;
			mp[sum]++;
			//cout << sum << " ";
		}
		//cout << endl;
		LL ret = 0;
		FOREACH(it, mp) {
			int cnt = it->second;
			ret += (LL)cnt * (cnt - 1) / 2;
		}
		cout << ret << endl;
	}
	return 0;
}

