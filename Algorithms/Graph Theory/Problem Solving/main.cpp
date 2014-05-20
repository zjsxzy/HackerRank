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

#define abs(x) ((x) > 0 ? (x) : -(x))
const int maxn = 305;
int N, K;
int v[maxn], cx[maxn], cy[maxn], adj[maxn][maxn], mk[maxn];

bool path(int i)
{
    for (int j = 1; j <= N; j++)
    {
        if (adj[i][j] && !mk[j])
        {
            mk[j] = true;
            if (cy[j] == -1 || path(cy[j]))
            {
                cx[i] = j;
                cy[j] = i;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()
{
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        memset(mk, 0, sizeof(mk));
        if (path(i)) res++;
    }
    return res;
}

int main()
{
//	freopen("in", "r", stdin);
	int Test;
	cin >> Test;
	while (Test--) {
		memset(adj, 0, sizeof(adj));
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> v[i];

		for (int i = 1; i <= N; i++)
			for (int j = i + 1; j <= N; j++)
				if (abs(v[j] - v[i]) >= K) adj[i][j] = 1;

		int ret = MaxMatch();
		cout << N - ret << endl;
	}
	return 0;
}
