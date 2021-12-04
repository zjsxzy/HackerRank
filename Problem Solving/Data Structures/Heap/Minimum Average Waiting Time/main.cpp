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
#include <cassert>
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

const int MAXN = 100000 + 5;
int n;
vector<pair<int, int> > p;

int main() {
	scanf("%d", &n);
	p.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	sort(p.begin(), p.end());
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 
	pq.push(MP(p[0].second, p[0].first));
	LL res = 0, cur = p[0].first;
	int i = 1;
	while (!pq.empty() || i < n) {
		while (i < n && p[i].first <= cur) {
			pq.push(MP(p[i].second, p[i].first));
			i++;
		}
		if (pq.empty() && i < n) {
			cur = p[i].first;
			pq.push(MP(p[i].second, p[i].first));
			i++;
		}
		pair<int, int> Top = pq.top();
		pq.pop();
		cur += (LL)Top.first;
		res += (LL)cur - (LL)Top.second;
	}
	cout << res / n << endl;
	return 0;
}

