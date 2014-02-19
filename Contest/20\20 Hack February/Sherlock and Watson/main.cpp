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

const int MAXN = 100000 + 5;
int N, K, Q;
int a[MAXN];

int main() {
	scanf("%d%d%d", &N, &K, &Q);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	K %= N;
	while (Q--) {
		int idx;
		scanf("%d", &idx);
		printf("%d\n", a[(idx - K + N) % N]);
	}
	return 0;
}

