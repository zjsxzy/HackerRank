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

int alpha[26];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		vector<int> h(26, 0);
		for (int j = 0; j < str.size(); j++) {
			if (!h[str[j] - 'a']) {
				h[str[j] - 'a'] = true;
				alpha[str[j] - 'a']++;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == n) {
			res++;
		}
	}
	cout << res << endl;
	return 0;
}

