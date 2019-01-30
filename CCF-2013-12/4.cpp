#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll; 
const int N=1000+10;
const ll MOD=1000000007; 
ll d[N][6];
int main()
{
	int n;
	scanf("%d",&n);
	memset(d,0,sizeof(d));
	d[0][0]=1;
	for(int i=1;i<n;i++)
	{
		d[i][0]=1; //只有数字2
		d[i][1]=(2*d[i-1][1]+d[i-1][0])%MOD; //有数字2,0 
		d[i][2]=(d[i-1][2]+d[i-1][0])%MOD; //有数字2,3 
		d[i][3]=(2*d[i-1][3]+d[i-1][1]+d[i-1][2])%MOD; //有数字0,2,3 
		d[i][4]=(2*d[i-1][4]+d[i-1][1])%MOD; //有数字0,1,2 
		d[i][5]=(2*d[i-1][5]+d[i-1][3]+d[i-1][4])%MOD; //有数字0,1,2,3
	}
	printf("%lld\n",d[n-1][5]);
	return 0;
}
