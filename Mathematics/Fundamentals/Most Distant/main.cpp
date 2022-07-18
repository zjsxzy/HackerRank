#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    double min_x = 1e9, max_x = 0, min_y = 1e9, max_y = 0;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        min_x = min(x, min_x);
        max_x = max(x, max_x);
        min_y = min(y, min_y);
        max_y = max(y, max_y);
    }
    auto dist = [&](double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    double res = max(max_x - min_x, max_y - min_y);
    res = max(res, dist(max_x, 0, 0, max_y));
    res = max(res, dist(max_x, 0, 0, min_y));
    res = max(res, dist(min_x, 0, 0, max_y));
    res = max(res, dist(min_x, 0, 0, min_y));
    printf("%.6f\n", res);
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

