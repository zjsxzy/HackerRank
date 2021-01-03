#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int n = 9;

bool magic(vector<int> &mat) {
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += mat[i * 3 + j];
		}
		if (sum != 15) return false;
	}
	for (int j = 0; j < 3; j++) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += mat[i * 3 + j];
		}
		if (sum != 15) return false;
	}
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += mat[i * 3 + i];
	}
	if (sum != 15) return false;
	sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += mat[i * 3 + 3 - i - 1];
	}
	if (sum != 15) return false;
	return true;
}

void solve() {
	vector<int> arr(n), mat(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mat[i] = i + 1;
	}
	int res = 1e9;
	do {
		int sum = 0;
		if (!magic(mat)) continue;
		for (int i = 0; i < n; i++) {
			sum += abs(arr[i] - mat[i]);
		}
		res = min(res, sum);
	} while (next_permutation(mat.begin(), mat.end()));
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

