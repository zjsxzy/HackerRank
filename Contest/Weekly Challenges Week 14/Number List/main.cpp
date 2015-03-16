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

const int MAXN = 200000 + 5;
int n, K;
int A[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input05.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &K);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		LL ret = (LL)n * (n + 1) / 2;
		for (int i = 1; i <= n; i++) {
			if (A[i] > K) continue;
			int cnt = 0;
			while (i <= n && A[i] <= K) {
				i++;
				cnt++;
			}
			ret -= (LL)cnt * (cnt + 1) / 2;
		}
		cout << ret << endl;
	}
	return 0;
}

