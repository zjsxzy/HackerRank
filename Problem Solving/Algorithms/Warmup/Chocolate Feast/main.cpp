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
	int Test;
	cin >> Test;
	while (Test--) {
		LL N, C, M;
		cin >> N >> C >> M;
		LL tot = N / C;
		LL res = tot;
		while (tot >= M) {
			res++;
			tot -= M;
			tot++;
		}
		cout << res << endl;
	}
	return 0;
}
