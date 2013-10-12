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

const int maxn = 200005;
int n;
int a[maxn];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	vector<pair<int, int> > ans;
	int close = 100000000;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] < close) {
			close = a[i] - a[i - 1];
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] == close) {
			ans.PB(MP(a[i - 1], a[i]));
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second;
		if (i == ans.size() - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}
