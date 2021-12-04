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

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		int n, K;
		scanf("%d%d", &n, &K);
		vector<int> A(n);
		multiset<int> B;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < n; i++) {
			int b;
			scanf("%d", &b);
			B.insert(b);
		}
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());

		bool flag = true;
		for (int i = 0; i < n; i++) {
			int val = K - A[i];
			multiset<int>::iterator it = lower_bound(B.begin(), B.end(), val);
			if (it == B.end()) {
				flag = false;
				break;
			} else {
				B.erase(it);
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
