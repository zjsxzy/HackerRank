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

const int MAXN = 250 + 5;
const LL inf = 1LL << 60;
int N, M, K;
int bikerX[MAXN], bikerY[MAXN], bikeX[MAXN], bikeY[MAXN];
LL dist[MAXN][MAXN];
int mk[MAXN], cx[MAXN], cy[MAXN];
vector<int> adj[MAXN];

void addEdge(int u, int v) {
	adj[u].PB(v);
	//cout << u << "->" << v << endl;
}

int path(int u) {
	for (int i = 0, v; i < adj[u].size(); i++) {
		if (!mk[v = adj[u][i]]) {
			mk[v] = 1;
			if (cy[v] == -1 || path(cy[v])) {
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch() {
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (cx[i] == -1) {
			memset(mk, 0, sizeof(mk));
			ret += path(i);
		}
	}
	return ret;
}

bool check(LL distance) {
	for (int i = 0; i < N; i++)
		adj[i].clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] <= distance) addEdge(i, j);
		}
	}
	int match = MaxMatch();
	return match >= K;
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", bikerX + i, bikerY + i);
	}
	for (int j = 0; j < M; j++) {
		scanf("%d%d", bikeX + j, bikeY + j);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist[i][j] = (LL)(bikerX[i] - bikeX[j]) * (bikerX[i] - bikeX[j]) + (LL)(bikerY[i] - bikeY[j]) * (bikerY[i] - bikeY[j]);
		}
	}
	LL lo = 0, hi = inf, ret = -1;
	while (lo <= hi) {
		LL mid = (lo + hi) >> 1;
		if (check(mid)) {
			ret = mid;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	cout << ret << endl;
	return 0;
}

