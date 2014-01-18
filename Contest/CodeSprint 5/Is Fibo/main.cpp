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

const LL MAXN = 10000000000L;
set<LL> st;

int main(int argc, char const *argv[])
{
	st.clear();
	LL a = 0, b = 1;
	for (LL c = a + b; c <= MAXN; c = a + b) {
		st.insert(c);
		a = b;
		b = c;
	}
	int ts;
	cin >> ts;
	while (ts--) {
		LL x;
		cin >> x;
		if (st.find(x) == st.end()) {
			puts("IsNotFibo");
		} else {
			puts("IsFibo");
		}
	}
	return 0;
}