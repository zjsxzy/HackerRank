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

const int MAXN = 555;
int n;
queue<LL> q;

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		while (!q.empty()) q.pop();
		q.push(9);
		while (!q.empty()) {
			LL x = q.front(); q.pop();
			if (x % n == 0) {
				printf("%lld\n", x);
				break;
			}

			x *= 10;
			if (x % n == 0) {
				printf("%lld\n", x);
				break;
			}
			q.push(x);

			x += 9;
			if (x % n == 0) {
				printf("%lld\n", x);
				break;
			}
			q.push(x);
		}
	}
	return 0;
}

