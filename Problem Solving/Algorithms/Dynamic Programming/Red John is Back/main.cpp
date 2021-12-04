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

const int maxn = 41;
int f[maxn], cnt[maxn];
vector<int> prime;

void getPrime(int n) {
	vector<bool> mk(n + 1);
	for (int i = 2; i <= n; i++) {
		if (!mk[i]) {
			prime.PB(i);
			for (int j = 2; i * j <= n; j++)
				mk[i * j] = true;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++)
		f[i] = 1;
	for (int i = 4; i < 41; i++)
		f[i] = f[i - 1] + f[i - 4];
	getPrime(f[40]);
	for (int i = 1; i <= 40; i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] > f[i]) break;
			cnt[i]++;
		}
	}
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", cnt[n]);
	}
	return 0;
}
