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

int cnt[56];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < SZ(s); i++) {
		cnt[s[i] - 'a']++;
	}
	int num = 0;
	for (int i = 0; i < 26; i++)
		if (cnt[i] & 1) num++;
	if (num <= 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
