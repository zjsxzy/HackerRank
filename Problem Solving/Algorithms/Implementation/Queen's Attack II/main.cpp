#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int n, k, xq, yq;
int res[8];

void horizontal(int x, int y) {
	if (x < xq) {
		res[6] = min(res[6], xq - x - 1);
	} else if (x > xq) {
		res[2] = min(res[2], x - xq - 1);
	}
}

void vertical(int x, int y) {
	if (y < yq) {
		res[4] = min(res[4], yq - y - 1);
	} else {
		res[0] = min(res[0], y - yq - 1);
	}
}

void diagonal(int x, int y) {
	if (x > xq && y > yq) {
		res[1] = min(res[1], x - xq - 1);
	} else if (x > xq && y < yq) {
		res[3] = min(res[3], x - xq - 1);
	} else if (x < xq && y < yq) {
		res[5] = min(res[5], xq - x - 1);
	} else if (x < xq && y > yq) {
		res[7] = min(res[7], xq - x - 1);
	}
}

void solve() {
	cin >> n >> k >> xq >> yq;
	res[0] = n - yq; res[1] = min(n - xq, n - yq);
	res[2] = n - xq; res[3] = min(n - xq, yq - 1); 
	res[4] = yq - 1; res[5] = min(xq - 1, yq - 1);
	res[6] = xq - 1; res[7] = min(xq - 1, n - yq);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if (y == yq) {
			horizontal(x, y);
		} else if (x == xq) {
			vertical(x, y);
		} else if (abs(x - xq) == abs(y - yq)) {
			diagonal(x, y);
		}
	}
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		ans += res[i];
	}
	cout << ans << endl;
}

int main() {
    solve();
    return 0;
}

