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

const int maxn = 100000 + 5;
int rem[maxn];

int main() {
	int Test;
	cin >> Test;
	while (Test--) {
		int x;
		cin >> x;
		if (x == 1 || x == 2 || x == 4) {
			cout << 2 << endl;
			continue;
		}
		memset(rem, -1, sizeof(rem));
		rem[0] = 0;
		rem[4 % x] = 1;
		int num = 4 % x;
		int a, b;
		for (int i = 2; i <= x + 1; i++) {
			if (rem[(num * 10 + 4) % x] != -1) {
				a = i - rem[(num * 10 + 4) % x];
				b = rem[(num * 10 + 4) % x];
				break;
			} else {
				rem[(num * 10 + 4) % x] = i;
				num = (num * 10 + 4) % x;
			}
		}
		cout << 2 * a + b << endl;
	}
	return 0;
}
