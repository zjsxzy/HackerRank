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
#include <cassert>
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

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		LL n, k;
		cin >> n >> k;
		LL x = n / 4;
		x*=2;
		bool bo = false;
		if (n % 4 == 0) {
		   if(x>=k)bo =1;
		}else if(n%4==1){
		   if(x+1>=k)bo=1;
		}else if(n%4==2){
		   if(x+1>=k)bo=1;
		}else if(n%4==3){
		   if(x+1>=k)bo=1;
		}
		if(bo){
			puts("Yes");
		}else{
			puts("No");
		}
		//puts(n / 2 >= k ? "Yes" : "No");
	}
	return 0;
}

