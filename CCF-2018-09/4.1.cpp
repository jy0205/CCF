#include<iostream>
#include<cstdlib>
using namespace std;
int t,count;
int a[400],b[400];//输入菜价，所求菜价 
bool f[301][301][301]; //储存状态信息，也就是dfs的n,x,y 
void dfs(int n,int x,int y)//分别是搜到第n天，b[n-1]（求到了第n-1天的菜价）,b[n]（求到了第n天的菜价）
{ 
	if(f[n][x][y])return;//剪枝，不加只有80分 
	f[n][x][y]=1;
	if(n==t-1) //最后一天菜价特殊处理，所以n只用等于t-1就够了 
	{
		if((3*a[n]-x)/2==a[t]||(3*a[n]-x+1)/2==a[t]||(3*a[n]-x+2)/2==a[t]) //最后一天菜价 
		{
			//cout<<count<<endl;
			for(int i=1;i<=n;++i)    //输出 
			cout<<b[i]<<" ";
			for(int i=0;i<3;++i)
			{
				if((3*a[n]-x+i)/2==a[t]) //输出最后一天菜价
				{
					cout<<3*a[n]-x-y+i;
					exit(0);  //直接结束程序，这样用时更短 
				}
			}
		}
		return;
	}
	for(int i=0;i<3;++i) 
	{
		b[n+1]=3*a[n]-x-y+i; //递推关系式 
		if(b[n+1]>=1)
		dfs(n+1,y,b[n+1]);
	}
}
int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	cin>>a[i];
	for(int i=1;i<=2*a[1];++i)
	{
		b[1]=i,b[2]=2*a[1]-i;  //第一天菜价，有两种可能 
		dfs(2,i,b[2]);
		b[1]=i,b[2]=2*a[1]-i+1; //第二种可能 
		dfs(2,i,b[2]);
	} 
	return 0;
}
