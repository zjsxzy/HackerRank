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
int rate[maxn], candy[maxn], idx[maxn];

bool cmp(int i, int j) {
	return rate[i] < rate[j];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rate[i];
		idx[i] = i;
	}
	sort(idx + 1, idx + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int cur = idx[i];
		int l = cur - 1, r = cur + 1;
		if (l >= 1 && rate[l] < rate[cur]) {
			candy[cur] = max(candy[cur], candy[l] + 1);
		}
		if (r <= n && rate[r] < rate[cur]) {
			candy[cur] = max(candy[cur], candy[r] + 1);
		}
		if (candy[cur] == 0) candy[cur] = 1;
	}
	LL res = 0;
	for (int i = 1; i <= n; i++)
		res += (LL)candy[i];
	cout << res << endl;
	return 0;
}
