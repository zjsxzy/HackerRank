#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

/*
 * Count inversion pairs by merge sort
 * Notice that the array is a[1], a[2], ..., a[N]
 */
const int maxn = 100005;
struct MergeSortForInv {
	int n;
	LL tot;
	int a[maxn], tmp[maxn];

	void init(int n) {
		this->n = n;
		tot = 0;
	}

	void add(int pos, int num) {
		a[pos] = num;
	}

	void merge(int l, int mid, int r)
	{
	    int i, j, t;
	    t = l;
	    i = l;
	    j = mid + 1;
	    while (t <= r)
	    {
	        if ((i <= mid) && ((j > r) || (a[i] > a[j])))
	        {
	            tmp[t] = a[i];
	            i++;
	        }
	        else
	        {
	            tmp[t] = a[j];
	            j++;
	            tot += i-l;
	        }
	        t++;
	    }
	    for (i = l; i <= r; i++)
	        a[i] = tmp[i];
	}

	void mergesort(int l, int r)
	{
	    int mid;
	    mid = (l + r) / 2;
	    if (l != r)
	    {
	        mergesort(l, mid);
	        mergesort(mid + 1, r);
	        merge(l, mid, r);
	    }
	}

	LL solve() {
		mergesort(1, n);//Notice merge a[1]...a[N]!
		return tot;
	}
}mg;

void solve() {
    int n;
    scanf("%d", &n);
    mg.init(n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        mg.add(i, x);
    }
    LL res = mg.solve();
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

