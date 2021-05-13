#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void output(vector<int> &arr) {
	for (auto &x : arr) {
		cout << x << " ";
	}
	cout << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x : arr) {
		cin >> x;
	}
	int tmp = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (tmp > arr[i]) {
			arr[i + 1] = tmp;
			output(arr);
			break;
		}
		arr[i + 1] = arr[i];
		output(arr);
	}
	if (tmp < arr[0]) {
		arr[0] = tmp;
		output(arr);
	}
}

int main() {
    solve();
    return 0;
}

