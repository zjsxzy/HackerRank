#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int swap = 0;
    for (int i = 1; i <= n; i++) {
        if (i != arr[i]) {
            swap++;
            int temp = arr[i];
            arr[i] = arr[pos[i]];
            arr[pos[i]] = temp;
            pos[temp] = pos[i];
        }
    }
    cout << swap << endl;
}

int main() {
    solve();
    return 0;
}

