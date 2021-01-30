#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> A(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> A[i][j];
		}
	}
	int area = 2 * h * w;
	for (int i = 0; i < h; i++) {
		area += A[i][0];
		for (int j = 1; j < w; j++) {
			area += abs(A[i][j] - A[i][j - 1]);
		}
		area += A[i][w - 1];
	}
	for (int i = 0; i < w; i++) {
		area += A[0][i];
		for (int j = 1; j < h; j++) {
			area += abs(A[j][i] - A[j - 1][i]);
		}
		area += A[h - 1][i];
	}
	cout << area << endl;
}

int main() {
    solve();
    return 0;
}

