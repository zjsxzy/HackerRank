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

const int maxn = 1000000 + 5;
int n;
int a[maxn];
vector<int> vec;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] -= i;
	}
	for (int i = 1; i <= n; i++) {
		int val = a[i];
		if (a[i] < 0) continue;
		int lo = 0, hi = vec.size() - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (vec[mid] <= val) lo = mid + 1;
			else hi = mid - 1;
		}
		if (vec.size() <= lo) vec.PB(val);
		else vec[lo] = val;
//		cout << a[i] << " " << vec.size() << endl;
	}
	cout << n - vec.size() << endl;
	return 0;
}
