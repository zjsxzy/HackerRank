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
		int val = arr[i];
		int j = i - 1;
		while (j >= 0 && val < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = val;
	}
	for (auto &x : arr) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
    solve();
    return 0;
}

