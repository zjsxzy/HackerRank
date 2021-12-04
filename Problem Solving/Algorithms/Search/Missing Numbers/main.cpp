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

const int MAXN = 20000 + 5;
const int BASE = 10000;
int n, m;
int cnt[MAXN];

int main() {
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[BASE + x]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		cnt[BASE + x]--;
	}
	for (int i = 0; i < (BASE << 1); i++) {
		if (cnt[i] == 0) continue;
		if (cnt[i] > 0) while(1);
		//for (; cnt[i] < 0; cnt[i]++) {
		printf("%d ", i - BASE);
		//}
	}
	puts("");
	return 0;
}

