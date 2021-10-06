#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

vector<int> left_node, right_node;
int swap_level;

void traverse(int node = 1) {
    if (node == -1) return;
    traverse(left_node[node]);
    cout << node << " ";
    traverse(right_node[node]);
    if (node == 1) cout << endl;
}

void swap(int level = 1, int node = 1) {
    if (node == -1) return;
    if (level % swap_level == 0) {
        int temp = left_node[node];
        left_node[node] = right_node[node];
        right_node[node] = temp;
    }
    swap(level + 1, left_node[node]);
    swap(level + 1, right_node[node]);
}

void solve() {
    int n;
    cin >> n;
    left_node.PB(0);
    right_node.PB(0);
    while (n--) {
        int l, r;
        cin >> l >> r;
        left_node.PB(l);
        right_node.PB(r);
    }
    int k;
    cin >> k;
    while (k--) {
        cin >> swap_level;
        swap();
        traverse();
    }
}

int main() {
    solve();
    return 0;
}

