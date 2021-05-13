#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x : arr) {
		cin >> x;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			} else {
				break;
			}
		}
		for (auto &x : arr) {
			cout << x << " ";
		}
		cout << endl;
	}
}

int main() {
    solve();
    return 0;
}

