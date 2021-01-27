#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

string next_permutation(string &str) {
	int len = SZ(str);
	int i = len - 2;
	while (i >= 0 && str[i] >= str[i + 1]) {
		i--;
	}
	if (i < 0) return "no answer";
	int j = len - 1;
	while (j >= 0 && str[i] >= str[j]) {
		j--;
	}
	swap(str[i], str[j]);
	reverse(str.begin() + i + 1, str.end());
	return str;
}

void solve() {
	string str;
	cin >> str;
	string res = next_permutation(str);
	cout << res << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
    return 0;
}

