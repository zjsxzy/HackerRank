#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

LL length(vector<pair<LL, LL>>& row) {
	sort(row.begin(), row.end());
	LL sum = 0, l = 0, r = 0;
	for (auto &p: row) {
		if (p.first <= r) {
			r = max(r, p.second);
		} else {
			if (r != 0) sum += r - l + 1;
			l = p.first, r = p.second;
		}
	}
	if (r != 0) sum += r - l + 1; 
	return sum;
}

void solve() {
	LL n, m, k;
	cin >> n >> m >> k;
	LL res = n * m;
	map<int, vector<pair<LL, LL>>> train;
	for (int i = 0; i < k; i++) {
		int r, a, b;
		cin >> r >> a >> b;
		train[r].emplace_back(a, b);
	}
	for (auto &[k, v]: train) {
		res -= length(v);
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

