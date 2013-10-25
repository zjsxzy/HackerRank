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

const int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

LL calc(int a, int b, int k) {
	long double temp = b * log10((long double)a);
	int t = floor(temp);
	temp = temp - t;
	return (LL)(pow(10.0, temp) * ten[min(t, k - 1)]);
}

LL quickpow(LL a, LL b, LL mod) {
	LL res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

int main() {
	int Test;
	cin >> Test;
	while (Test--) {
		int n, k;
		cin >> n >> k;
		cout << calc(2, n - 1, k) + quickpow(2ll, n - 1, ten[k]) << endl;
	}
	return 0;
}
