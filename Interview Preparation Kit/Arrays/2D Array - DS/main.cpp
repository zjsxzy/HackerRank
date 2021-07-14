#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int n = 6;
int arr[9][9];

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int mx = -INT_MAX;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			int sum = arr[i][j];
			for (int k = -1; k <= 1; k++) {
				sum += arr[i - 1][j + k];
				sum += arr[i + 1][j + k];
			}
			if (sum > mx) mx = sum;
		}
	}
	cout << mx << endl;
}

int main() {
    solve();
    return 0;
}

