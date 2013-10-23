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

const int maxn = 100005;
int n;
int t[maxn], f[maxn], dp[maxn];
pair<int, int> p[maxn];
vector<int> vec;

int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> t[i] >> f[i];
			p[i].first = t[i] - f[i];
			p[i].second = t[i] + f[i];
		}
		sort(p + 1, p + n + 1);
		/* O(n^2)
		int res = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (p[i].second < p[j].second) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(res, dp[i]);
		}
		cout << res << endl;
		*/
		vec.clear();
		for (int i = 1; i <= n; i++) {
			int val = p[i].second;
			int lo = 0, hi = vec.size() - 1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (vec[mid] > val) lo = mid + 1;
				else hi = mid - 1;
			}
			if (vec.size() <= lo) vec.PB(val);
			else vec[lo] = val;
		}
		cout << vec.size() << endl;
	}
	return 0;
}
