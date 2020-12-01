#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> b >> a;
	int res = 2 * a / b;
	if (2 * a % b) res++;
	cout << res << endl;
	return 0;
}
