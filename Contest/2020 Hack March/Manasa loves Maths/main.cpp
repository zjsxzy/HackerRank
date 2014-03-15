#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

string num;
int check(int a, int b, int c) {
	vector<int> vec;
	vec.push_back(a * 100 + b * 10 + c);
	vec.push_back(a * 100 + c * 10 + b);
	vec.push_back(b * 100 + a * 10 + c);
	vec.push_back(b * 100 + c * 10 + a);
	vec.push_back(c * 100 + a * 10 + b);
	vec.push_back(c * 100 + b * 10 + a);
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] % 8 == 0) {
			//cout << vec[i] << endl;
			return true;
		}
	return false;
}
int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		cin >> num;
		bool flag = false;
		if (num.size() == 1) {
			puts((num[0] == '0' || num[0] == '8') ? "YES" : "NO");
			continue;
		}
		if (num.size() == 2) {
			int a = num[0] - '0', b = num[1] - '0';
			puts(((a * 10 + b) % 8 == 0 || (b * 10 + a) % 8 == 0) ? "YES" : "NO");
			continue;
		}
		for (int i = 0; i < num.size() && !flag; i++) {
			for (int j = i + 1; j < num.size() && !flag; j++) {
				for (int k = j + 1; k < num.size() && !flag; k++) {
					int a = num[i] - '0', b = num[j] - '0', c = num[k] - '0';
					if (check(a, b, c)) flag = true;
				}
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
