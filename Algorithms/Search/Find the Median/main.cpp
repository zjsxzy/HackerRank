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

const int maxn = 1000005;
int n;
int a[maxn];

int findKth(int lo, int hi, int k) {
	if (k <= 0 || k > hi - lo + 1) return -1;
	int pivot = lo + rand() % (hi - lo + 1);
	swap(a[lo], a[pivot]);
	int p = lo, cnt = 1;
	for (int i = lo + 1; i <= hi; i++) {
		if (a[i] < a[lo]) {
			swap(a[++p], a[i]);
			cnt++;
		}
	}
	swap(a[p], a[lo]);
	if (k < cnt) {
		return findKth(lo, p - 1, k);
	} else if (k > cnt) {
		return findKth(p + 1, hi, k - cnt);
	} else {
		return a[p];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int res = findKth(0, n - 1, (n + 1) / 2);
	cout << res << endl;
	return 0;
}
