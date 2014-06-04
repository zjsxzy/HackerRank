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

const int MAXN = 100000 + 10;
char str[MAXN];
bool isPalindrom(int l, int r) {
	for (; l < r; l++, r--) {
		if (str[l] != str[r]) return false;
	}
	return true;
}
int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%s", str);
		int n = strlen(str);
		int l = 0, r = n - 1, ret = -1;
		while (l < r) {
			if (str[l] == str[r]) {
				l++; r--;
				continue;
			} else {
				if (isPalindrom(l + 1, r)) {
					ret = l;
				} else ret = r;
				break;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}

