#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 10000000;
int que[maxn];
int front, rear;

void enqueue(int num) {
    que[rear] = num;
    rear++;
}

void dequeue() {
    front++;
}

void print() {
    cout << que[front] << endl;
}

void solve() {
    int q;
    cin >> q;
    front = rear = 0;
    while (q--) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else {
            print();
        }
    }
}

int main() {
    solve();
    return 0;
}

