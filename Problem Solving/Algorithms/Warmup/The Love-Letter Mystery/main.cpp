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

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		string str;
		cin >> str;
		int l = 0, r = str.size() - 1;
		int ret = 0;
		for (; l < r; l++, r--) {
			int ch1 = str[l], ch2 = str[r];
			ret += abs(ch1 - ch2);
		}
		cout << ret << endl;
	}
	return 0;
}

