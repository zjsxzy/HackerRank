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

const LL MOD = 1000000007;
const int maxn = 50005;
int card[maxn];
int n;

int main() {
	int Test;
	cin >> Test;
	while (Test--) {
		cin >> n;
		memset(card, 0, sizeof(card));
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			card[x]++;
		}
		for (int i = 1; i <= n; i++) {
			card[i] += card[i - 1];
		}
		LL res = 1;
		for (int i = 0; i < n; i++) {
			res = res * max(0, card[i] - i) % MOD;
		}
		cout << res << endl;
	}
	return 0;
}
