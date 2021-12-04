#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;


long long solve(string &s) {
	if (s[0] == '0') return -1;
	int n = SZ(s);
	for (int len = 1; len * 2 <= n; len++) {
		long long first_num = stoll(s.substr(0, len));
		long long num = first_num;
		string news = to_string(num);
		while (news.size() <= n) {
			if (news == s) {
				return first_num;
			} else {
				num++;
				news += to_string(num);
			}
		}
	}
	return -1;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		long long res = solve(s);
		if (res > 0) {
			cout << "YES " << res << endl;
		} else {
			cout << "NO" << endl;
		}
	}
    return 0;
}

