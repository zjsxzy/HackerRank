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

const int INF = 0x7fffffff;

int work(int n)
{
	if ((n & 1) > 0)
		return 1;
	int sgn = 0;
	for (int a = 1; a <= n; a <<= 1, sgn++);
	
	int result = INF;
	int sgTotal = sgn ^ 1;
	for (int i = 1; i <= sgn; i++)
	{
		int sgTo = sgTotal ^ i;
		if (i > sgTo)
		{
			int from = 1 << (i - 1);
			int to = i == sgTo + 1 ? (from >> 1) : ((1 << sgTo) - 1);
			if (result > from - to)
			{
				//printf("%d %d->%d", i, from, to);
			}
			result = min(result, from - to);
		}
	}
	
	return result;
}

int main() 
{
	int test;	scanf("%d", &test);
	while (test-- > 0)
	{
		int n; scanf("%d", &n);
		int result = work(n);
		printf("%d\n", result);
	}
}
