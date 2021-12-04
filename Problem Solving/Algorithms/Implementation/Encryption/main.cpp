#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	string str;
	cin >> str;
	int len = (int)str.size();
	int lb = (int)sqrt(1.0 * len);
	int ub = (int)ceil(sqrt(1.0 * len));
	int r = 0, c = 0, res = INT_MAX;
	for (int row = lb; row <= ub; row++) {
		for (int col = row; col <= ub; col++) {
			if (row * col >= len && row * col < res) {
				res = row * col;
				r = row;
				c = col;
			}
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (j * c + i < len) {
				cout << str[j * c + i];
			}
		}
		cout << " ";
	}
}

int main() {
    solve();
    return 0;
}

