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

const int MAXN = 2000000 + 5;
const LL MOD = 1000000000 + 7;
struct line {
	LL val;
	bool hor;
	line() {}
	line(LL val, bool hor) : val(val), hor(hor) {}
	bool operator < (const line &pt) const {
		return val > pt.val;
	}
};
vector<line> vec;
int n, m;

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &m);
		vec.clear();
		for (int i = 1; i < n; i++) {
			int val;
			scanf("%d", &val);
			vec.PB(line(val, true));
		}
		for (int i = 1; i < m; i++) {
			int val;
			scanf("%d", &val);
			vec.PB(line(val, false));
		}
		sort(vec.begin(), vec.end());
		LL cost = 0, h = 0, v = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].hor) {
				cost = (cost + vec[i].val * (v + 1)) % MOD;
				h++;
			} else {
				cost = (cost + vec[i].val * (h + 1)) % MOD;
				v++;
			}
			//cout << cost << endl;
		}
		cout << cost << endl;
		//cout << endl;
	}
	return 0;
}

