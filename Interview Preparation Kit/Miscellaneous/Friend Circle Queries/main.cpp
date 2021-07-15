#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 200005;
int f[MAXN];

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void solve() {
	int q;
	cin >> q;
	vector<pair<int, int>> query; 
	map<int, int> idx;
	int nodes = 0;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		if (idx.find(u) == idx.end()) {
			idx[u] = nodes++;
		}
		if (idx.find(v) == idx.end()) {
			idx[v] = nodes++;
		}
		query.emplace_back(idx[u], idx[v]);
	}

	vector<int> cnt(nodes, 1);
	for (int i = 0; i < nodes; i++) {
		f[i] = i;
	}

	int max_circle = 1;
	for (int i = 0; i < q; i++) {
		int x = find(query[i].first), y = find(query[i].second);
		if (x != y) {
			cnt[x] += cnt[y];
			f[y] = x;
			if (cnt[x] > max_circle) {
				max_circle = cnt[x];
			}
		}
		cout << max_circle << endl;
	}

}

int main() {
    solve();
    return 0;
}

