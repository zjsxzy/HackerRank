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
	for (auto &x: arr) {
		cin >> x;
	}
	int swap = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap++;
			}
		}
	}
	cout << "Array is sorted in " << swap << " swaps." << endl;
	cout << "First Element: " << arr[0] << endl;
	cout << "Last Element: " << arr[n - 1] << endl;
}

int main() {
    solve();
    return 0;
}

