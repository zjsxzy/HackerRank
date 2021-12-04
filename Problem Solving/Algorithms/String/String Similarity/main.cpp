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

void ExtendedKMP(char a[], char b[], int M, int N, int nxt[], int ret[]) {
	int i, j, k;
	for (j = 0; 1 + j < M && a[j] == a[1 + j]; j++);
	nxt[1] = j;
	k = 1;
	for (i = 2; i < M; i++) {
		int len = k + nxt[k], L = nxt[i - k];
		if (L < len - i) {
			nxt[i] = L;
		} else {
			for (j = max(0, len - i); i + j < M && a[j] == a[i + j]; j++);
			nxt[i] = j;
			k = i;
		}
	}
	return;
	for (j = 0; j < N && j < M && a[i] == b[j]; j++);
	ret[0] = j;
	k = 0;
	for (i = 1; i < N; i++) {
		int len = k + ret[k], L = nxt[i - k];
		if (L < len - i) {
			ret[i] = L;
		} else {
			for (j = max(0, len - i); j < M && i + j < N && a[i] == b[i + j]; j++);
			ret[i] = j;
			k = i;
		}
	}
}

const int maxn = 100005;
int n, nxt[maxn], ret[maxn];
char str[maxn];

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%s", str);	
		n = strlen(str);
		ExtendedKMP(str, str, n, n, nxt, ret);
		LL res = n;
		for (int i = 1; i < n; i++)
			res += nxt[i];
		cout << res << endl;
	}
	return 0;
}
