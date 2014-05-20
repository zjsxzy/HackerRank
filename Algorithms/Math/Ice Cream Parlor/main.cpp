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
typedef long long LL;

int main(int argc, char const *argv[])
{
	int Test;
	cin >> Test;
	while (Test--) {
		int C, L;
		cin >> C >> L;
		vector<int> v(L);
		vector<vector<int> > vec(10005);
		for (int i = 0; i < L; i++) {
			cin >> v[i];
			vec[v[i]].push_back(i + 1);
		}
		bool flag = true;
		for (int i = 0; i < L && flag; i++) {
			int x = C - v[i];
			if (x < 0 || x > 10000) continue;
			if (x == v[i]) {
				if (vec[x].size() >= 2) {
					cout << i + 1 << " " << vec[x][1] << endl;
					flag = false;
				}
			} else {
				if (vec[x].size() >= 1) {
					cout << i + 1 << " " << vec[x][0] << endl;
					flag = false;
				}
			}
		}
	}
	return 0;
}
