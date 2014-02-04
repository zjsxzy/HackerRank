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

#define maxn 100005
#define th(x) this->x = x
const LL mod = 100711433;
LL quickpow(LL x, LL b) {
	LL ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = ret * x % mod;
		x = x * x % mod;
	}
	return ret;
}
void Add(LL &a, LL b) {
	a = (a + b + mod) % mod;
}
LL R, InvR;
int n, U, Q;
LL disL[maxn], disR[maxn], sum[maxn];
int rmq[2*maxn];
struct ST {
	int mm[2*maxn];
	int best[20][2*maxn];
	void init(int n) {
		int i,j,a,b;
		mm[0]=-1;
		for(i=1; i<=n; i++) {
			mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
			best[0][i]=i;
		}
		for(i=1; i<=mm[n]; i++) {
			for(j=1; j<=n+1-(1<<i); j++) {
				a=best[i-1][j];
				b=best[i-1][j+(1<<(i-1))];
				best[i][j]=rmq[a] < rmq[b]?a:b;
			}
		}
	}
	int query(int a, int b) {
		if(a > b)	swap(a, b);
		int t;
		t=mm[b-a+1];
		a=best[t][a];
		b=best[t][b-(1<<t)+1];
		return rmq[a] < rmq[b] ? a : b;
	}
};
//下面是LCA2RMQ开始
struct Nod {
	int b, nxt;
	void init(int b, int nxt) {
		th(b);	th(nxt);
	}
};
/**
	lca转化为rmq问题
	注意: 
		1.maxn为最大节点数, ST的数组和F、buf要设置为2*maxn!!!!!
		2.ST类为1开始，此类依然为0开始!
		3.F是欧拉序列,rmq是深度序列,P某点在欧拉序列中第一次出现的位置
*/
struct LCA2RMQ {
	int n;							//节点个数
	Nod buf[2*maxn];	int len;	int E[maxn];	//Tree	资源
	int V[2*maxn], route[maxn];				//路径的权，根到某点的路径和
	char vis[maxn];						//0没有访问，1正在访问
	int Parent[maxn];
	
	ST st;							//Spare-Table...
	int F[2*maxn], P[maxn], cnt;	//介绍如上,cnt为计数器,lev为dfs时层数(减少递归栈大小)
	
	void init(int n) {
		th(n);
		len = 0;
		memset(Parent, 0, sizeof(Parent));
		memset(E, 255, sizeof(E));
	}
	void addEdge(int a, int b, int v) {
		buf[len].init(b, E[a]);		V[len] = v;		E[a] = len ++;
		buf[len].init(a, E[b]);		V[len] = v;		E[b] = len ++;
	}
	int query(int a, int b) {				//传入两个节点，返回他们lca节点编号
		return F[st.query(P[a], P[b])];
	}
	//1.【递归版】
	void dfs(int a, int lev) {
		vis[a] = 1;
		
		++ cnt;
		F[cnt] = a;
		rmq[cnt] = lev;
		P[a] = cnt;
		for(int i = E[a]; i != -1; i = buf[i].nxt) {
			if(vis[buf[i].b])	continue;
			Parent[buf[i].b] = a;
			route[buf[i].b] = route[a] + V[i];
			dfs(buf[i].b, lev+1);
			++ cnt;
			F[cnt] = a;
			rmq[cnt] = lev;
		}
	}
	void solve(int root) {
		memset(vis, 0, sizeof(vis));
		route[root] = cnt = 0;
		dfs(root, 0);
		st.init(2*n-1);
	}

	void Update() {
		dfs2(0, -1);
		memset(vis, 0, sizeof(vis));
		bfs(1);
	}
	void dfs2(int a, int fa) {
		for (int i = E[a]; i != -1; i = buf[i].nxt) {
			if (buf[i].b == fa) continue;
			dfs2(buf[i].b, a);
			Add(disL[a], disL[buf[i].b] * R % mod);
			Add(disR[a], disR[buf[i].b] * InvR % mod);
		}
	}
	void bfs(int root) {
		queue<int> q;
		q.push(root);
		while (!q.empty()) {
			int a = q.front(); q.pop();
			Add(sum[a], disL[a] + disR[a]);
			//cout << a << " " << sum[a] << endl;
			vis[a] = true;
			for (int i = E[a]; i != -1; i = buf[i].nxt) {
				if (vis[buf[i].b]) continue;
				Add(sum[buf[i].b], sum[a]);
				q.push(buf[i].b);
			}
		}
	}
	
} lca;

int main() {
	memset(disL, 0, sizeof(disL));
	memset(disR, 0, sizeof(disR));
	memset(sum, 0, sizeof(sum));
	cin >> n >> R;
	R %= mod;
	InvR = quickpow(R, mod - 2);
	lca.init(n + 1);
	lca.addEdge(0, 1, 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		lca.addEdge(a, b, 1);
	}
	lca.solve(0);
	cin >> U >> Q;
	while (U--) {
		int x, y;
		LL st;
		cin >> x >> y >> st;
		int anc = lca.query(x, y);
		if (R) {
			LL left = quickpow(R, lca.route[x] - lca.route[anc]);
			LL right = quickpow(R, lca.route[y] - lca.route[anc]);
			Add(disL[x], st);
			Add(disR[y], st * left % mod * right % mod);
			Add(disR[anc], -(st * left % mod));
			Add(disL[lca.Parent[anc]], -(st * left % mod * R % mod));
		} else {
			Add(disL[x], st);
		}
	}
	lca.Update();
	while (Q--) {
		int x, y;
		cin >> x >> y;
		int anc = lca.query(x, y);
		cout << (sum[x] + sum[y] - sum[anc] * 2 + disL[anc] + disR[anc] + mod * 2) % mod << endl;
	}
	return 0;
}

