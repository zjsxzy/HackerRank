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

int A, B;
int calc(int L) {
	if (L == 0) return 0;
	return int(sqrt(L));
}
int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &A, &B);
		cout << calc(B) - calc(A - 1) << endl;
	}
	return 0;
}

