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

const int MAXN = 1000 + 5;
int X, N, res;
vector<int> num;
vector<bool> vst;

int nth_power(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

void solve(int cur, int last) {
    if (cur == X) {
        res++;
    } else if (cur > X) {
        return;
    }
    for (int i = last; i < num.size(); i++) {
        if (!vst[i]) {
            vst[i] = true;
            solve(cur + num[i], i + 1);
            vst[i] = false;
        }
    }
}

int main() {
    cin >> X >> N;
    for (int i = 1; i <= X; i++) {
        int val = nth_power(i, N);
        if (val <= X) {
            num.push_back(val);
            vst.push_back(false);
        } else {
            break;
        }
    }
    res = 0;
    solve(0, 0);
    cout << res << endl;
    return 0;
}
