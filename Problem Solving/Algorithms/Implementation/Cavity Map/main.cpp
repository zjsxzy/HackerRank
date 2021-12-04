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

const int MAXN = 105;
int n;
string mat[MAXN];

int get_val(int i, int j) {
	return mat[i][j] - '0';
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	for (int i = 0; i < n; i++) {
		string res;
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
				res += mat[i][j];
			} else {
				if (get_val(i, j) > get_val(i - 1, j) && get_val(i, j) > get_val(i, j - 1) && \
					get_val(i, j) > get_val(i + 1, j) && get_val(i, j) > get_val(i, j + 1)) {
					res += 'X';
				} else {
					res += mat[i][j];
				}
			}
		}
		cout << res << endl;
	} 
	return 0;
}

