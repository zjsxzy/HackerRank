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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int maxNode = 100005;
struct Treap {
	int root, treapCnt, key[maxNode], priority[maxNode], childs[maxNode][2], cnt[maxNode], size[maxNode];

	bool flag;

	Treap() {
		root = 0;
		treapCnt = 1;
		priority[0] = INT_MAX;
		size[0] = 0;
	}

	void update(int x) {
		size[x] = size[childs[x][0]] + cnt[x] + size[childs[x][1]];
	}

	void rotate(int &x, int t) {
		int y = childs[x][t];
		childs[x][t] = childs[y][1 - t];
		childs[y][1 - t] = x;
		update(x);
		update(y);
		x = y;
	}

	void __insert(int &x, int k) {
		if (x) {
			if (key[x] == k) {
				cnt[x]++;
			} else {
				int t = key[x] < k;
				__insert(childs[x][t], k);
				if (priority[childs[x][t]] < priority[x]) {
					rotate(x, t);
				}
			}
		} else {
			x = treapCnt++;
			key[x] = k;
			cnt[x] = 1;
			priority[x] = rand();
			childs[x][0] = childs[x][1] = 0;
		}
		update(x);
	}

	void __erase(int &x, int k) {
		if (!flag) return;
		if (key[x] == k) {
			if (cnt[x] > 1) {
				cnt[x]--;
			} else {
				if (childs[x][0] == 0 && childs[x][1] == 0) {
					x = 0;
					return;
				}
				int t = priority[childs[x][0]] > priority[childs[x][1]];
				rotate(x, t);
				__erase(x, k);
			}
		} else {
			if (childs[x][key[x] < k] == 0) {
				flag = false;
				return;
			}
			__erase(childs[x][key[x] < k], k);
		}
		update(x);
	}

	int __getKth(int &x, int k) {
		if (k <= size[childs[x][0]]) {
			return __getKth(childs[x][0], k);
		}
		k -= size[childs[x][0]] + cnt[x];
		if (k <= 0) {
			return key[x];
		}
		return __getKth(childs[x][1], k);
	}

	//插入元素的值
	void insert(int k) {
		__insert(root, k);
	}

	//删除元素的值
	bool erase(int k) {
		flag = true;
		__erase(root, k);
		return flag;
	}

	//返回treap中第K小元素
	int getKth(int k) {
		return __getKth(root, k);
	}
};

int main() {
	Treap treap;
	int n;
	cin >> n;
	int tot = 0;
	while (n--) {
		string op;
		int x;
		cin >> op >> x;
		bool flag = true;
		if (op[0] == 'a') {
			treap.insert(x);
			tot++;
		} else {
			flag = treap.erase(x);
			if (flag) tot--;
		}
		if (!flag) {
			cout << "Wrong!" << endl;
			continue;
		}
		if (tot % 2 == 1) {
			cout << treap.getKth((tot + 1) / 2) << endl;
		} else {
			int k = tot / 2;
			LL res = (LL)treap.getKth(k) + treap.getKth(k + 1);
			if (res % 2 == 0) cout << res / 2 << endl;
			else {
				cout << res / 2 << ".5" << endl;
			}
		}
	}
	return 0;
}
