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

const int maxn = 50005;
int n;
LL price[maxn];

int main() {
	int Test;
	cin >> Test;
	while (Test--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> price[i];
		price[0] = 100005;
		LL mx = price[n], res = 0, cnt = 0, sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (price[i] < mx) {
				cnt++;
				sum += price[i];
			} else {
				res += cnt * mx - sum;
				cnt = 0;
				sum = 0;
				mx = price[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}
