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

const int MAXN = 10000 + 5;
char A[MAXN], B[MAXN];
int cntA[30], cntB[30];

int main() {
	scanf("%s\n%s", A, B);
	int lenA = strlen(A), lenB = strlen(B);
	for (int i = 0; i < lenA; i++) {
		cntA[A[i] - 'a']++;
	}
	for (int i = 0; i < lenB; i++) {
		cntB[B[i] - 'a']++;
	}
	int ret = 0;
	for (int i = 0; i < 26; i++) {
		ret += abs(cntA[i] - cntB[i]);
	}
	printf("%d\n", ret);
	return 0;
}

