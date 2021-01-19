#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	vector<int> row(n), col(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			col[j] += mat[i][j];
			row[i] += mat[i][j];
		}
	}
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	for (int i = 0; i < n; i++) {
		if (row[i] != col[i]) {
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << "Possible" << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
    return 0;
}

