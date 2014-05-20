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

int main() {
	int N;
	LL C;
	scanf("%d%lld", &N, &C);
	vector<int> a(N), b(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	int ret = 0;
	for (int k = 0; k < N; k++) {
		int cur = k;
		LL sum = 0;
		bool flag = true;
		do {
			sum = min(C, sum + a[cur]);
			sum -= b[cur];
			if (sum < 0) {
				flag = false;
				break;
			}
			cur = (cur + 1) % N;
		} while (cur != k);
		ret += (flag == true);
	}
	printf("%d\n", ret);
	return 0;
}

