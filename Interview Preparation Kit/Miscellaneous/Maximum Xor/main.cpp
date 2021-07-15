#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 100005;
struct Trie {
    struct Tnode {
        int next[2];
        int terminate;
    }chd[MAXN * 30];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
    }

    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int c = (x & (1 << i)) > 0 ? 1 : 0; // ith bit is 1 or 0
            if (!chd[p].next[c]) {
                memset(chd[size].next, 0, sizeof(chd[size].next));
                chd[size].terminate = -1;
                chd[p].next[c] = size++;
            }
            p = chd[p].next[c];
        }
        chd[p].terminate = x;
    }

    int find(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int c = (x & (1 << i)) > 0 ? 1 : 0; // ith bit is 1 or 0
            if (chd[p].next[1 - c]) {
                p = chd[p].next[1 - c];
            } else {
				p = chd[p].next[c];
			}
        }
		return chd[p].terminate;
    }
}trie;

void solve() {
    int n, m;
    cin >> n;
    vector<int> arr(n);
	trie.init();
    for (auto &x: arr) {
        cin >> x;
		trie.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
		int x = trie.find(q);
		cout << (q ^ x) << endl;
    }
}

int main() {
    solve();
    return 0;
}

