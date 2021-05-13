#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	cin >> n;
	string pwd;
	cin >> pwd;
	bool check[4] = {false};
	for (auto &c : pwd) {
		if (c >= 'A' && c <= 'Z') {
			check[0] = true;
		} else if (c >= 'a' && c <= 'z') {
			check[1] = true;
		} else if (c >= '0' && c <= '9') {
			check[2] = true;
		} else {
			check[3] = true;
		}
	}
	int con = 0;
	for (int i = 0; i < 4; i++) {
		if (!check[i]) {
			con++;
		}
	}
	cout << max(con, 6 - n) << endl;
}

int main() {
    solve();
    return 0;
}

