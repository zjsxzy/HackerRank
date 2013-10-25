#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
typedef long long lint;
typedef long double double64;
lint powm(lint a,int b,lint MOD)
{
	lint ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;	
	}
	return ans;
}
int main()
{
	int t,n,k,a,b,i,m;
	scanf("%d",&t);
	int A[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	while(t--)
	{
		scanf("%d%d",&m,&k);
                m-=1;
                n=2;
		double64 logval = m * log10(1.0L*n);
		double64 mantissa = logval - floor(logval);
		logval = k-1 + mantissa;
		a=(int)(exp(logval*log(10)));
		b=powm((lint)(n),m,(lint)(A[k]));
		cout << (lint)a << " " << (lint)b << endl;
//		printf("%lld\n",((lint)a+(lint)b));		
	}
	return 0;
}
