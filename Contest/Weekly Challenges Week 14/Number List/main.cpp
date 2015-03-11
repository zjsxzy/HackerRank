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
int A[MAXN], L[MAXN], R[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &K);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		A[0] = A[n + 1] = INT_MAX;
		for (int i = 1; i <= n; i++) {
			L[i] = i;
			while (A[i] > A[L[i] - 1]) {
				L[i] = L[L[i] - 1];
			}
		}
		for (int i = n; i >= 1; i--) {
			R[i] = i;
			while (A[i] > A[R[i] + 1]) {
				R[i] = R[R[i] + 1];
			}
		}
		LL ret = 0;
		for (int i = 1; i <= n; i++) {
			if (A[i] > K) {
				ret += (LL)(i - L[i] + 1) * (R[i] - i + 1);
			}
		}
		cout << ret << endl;
	}
	return 0;
}

