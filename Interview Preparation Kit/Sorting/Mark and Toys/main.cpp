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

int main() {
	int n, K;
	cin >> n >> K;
	vector<int> price(n);
	for (int i = 0; i < n; i++)
		cin >> price[i];
	sort(price.begin(), price.end());
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (K == 0) break;
		if (K < 0) {
			ret--;
			break;
		}
		K -= price[i];
		ret++;
	}
	cout << ret << endl;
	return 0;
}

