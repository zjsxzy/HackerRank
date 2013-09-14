#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int n, k;
int a[maxn];
map<int, int> mp;

int main() {
//	freopen("in.txt", "r", stdin);
	mp.clear();
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	sort(a, a + n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int l = i + 1, r = n - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] - a[i] == k) {
				ret += mp[a[mid]];
				break;
			}
			if (a[mid] - a[i] > k) r = mid - 1;
			else l = mid + 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}
