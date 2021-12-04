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
	int p = arr[0];
	arr.erase(arr.begin());

	vector<int> left, right;
	for (auto &x : arr) {
		(x > p) ? right.push_back(x) : left.push_back(x);
	}
	for (auto &x : left) {
		cout << x << " ";
	}
	cout << p << " ";
	for (auto &x : right) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
    solve();
    return 0;
}

