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

const int MAXN = 505;
const int INF = 0x3f3f3f3f;
int v;
int w[MAXN][MAXN], d[MAXN][MAXN];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void output(pair<int, int> p) {
	int g = gcd(p.first, p.second);
	printf("%d/%d\n", p.first / g, p.second / g);
}

LL compare(pair<int, int> a, pair<int, int> b) {
	LL t = (LL)a.first * b.second - (LL)a.second * b.first;
	return t;
}

int main() {
	while (~scanf("%d", &v)) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				scanf("%d", &w[i][j]);
				if (i == j) w[i][j] = INF;
			}
		}
		for (int i = 0; i <= v + 1; i++) {
			for (int j = 0; j < v + 1; j++) {
				d[i][j] = INF;
			}
		}
		int s = v++;
		for (int i = 0; i < v - 1; i++) {
			w[s][i] = 0;
			w[i][s] = INF;
		}
		w[s][s] = INF;

		d[0][s] = 0;
		for (int k = 0; k < v; k++) {
			for (int i = 0; i < v; i++) {
				for (int j = 0; j < v; j++) {
					if (d[k][i] + w[i][j] < d[k + 1][j]) {
						d[k + 1][j] = d[k][i] + w[i][j];
					}
				}
			}
		}
		pair<int, int> ret = MP(INF, 1);
		for (int i = 0; i < v - 1; i++) {
			if (d[v][i] == INF) continue;
			pair<int, int> maxw = MP(-INF, 1);
			for (int k = 0; k < v - 1; k++) {
				if (compare(MP(d[v][i] - d[k][i], v - k), maxw) > 0)
					maxw = MP(d[v][i] - d[k][i], v - k);
			}
			if (compare(maxw, ret) < 0)
				ret = maxw;
		}
		output(ret);
	}
	return 0;
}

