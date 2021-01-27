#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (auto &s : grid) {
		cin >> s;
	}
	int r, c;
	cin >> r >> c;
	vector<string> pattern(r);
	for (auto &s : pattern) {
		cin >> s;
	}

	for (int i = 0; i + r <= n; i++) {
		for (int j = 0; j + c <= m; j++) {
			if (grid[i].compare(j, c, pattern[0]) == 0) {
				bool match = true;
				for (int k = 1; k < r; k++) {
					if (grid[i + k].compare(j, c, pattern[k]) != 0) {
						match = false;
						break;
					}
				}
				if (match) {
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
    return 0;
}

