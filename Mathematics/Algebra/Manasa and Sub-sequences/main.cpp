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
#include <cassert>
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

const LL MOD = 1000000000 + 7;
string str;
int n;

LL quickpow(LL a, LL x) {
	LL ret = 1;
	for (; x; x >>= 1) {
		if (x & 1) ret = ret * a % MOD;
		a = a * a % MOD;
	}
	return ret;
}

int main() {
	cin >> str;
	LL ret = 0;
	for (int i = 0; i < str.size(); i++) {
		int x = str[i] - '0';
		int n = i, m = str.size() - n - 1;
		LL temp = 1;
		temp *= (LL)x; temp %= MOD;
		temp *= (LL)quickpow(2LL, n); temp %= MOD;
		temp *= (LL)quickpow(11LL, m); temp %= MOD;
		ret += temp; ret %= MOD;
	}
	cout << ret << endl;
	return 0;
}

