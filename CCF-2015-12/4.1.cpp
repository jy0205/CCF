
#include<iostream>  
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set> 
#include<stack>
#include<queue>
using namespace std;
const int N=10000+10;
set<int> s[N];
stack<int> path;
int n,m;
int uf[N],num[N];
int uf_find(int u)
{
	if(uf[u]==-1) return u;
	return uf[u]=uf_find(uf[u]);
}
void dfs(int u)
{
	while(!s[u].empty())
	{
		int v=*s[u].begin();
		s[u].erase(s[u].begin());
		s[v].erase(u);
		dfs(v);
	}
	path.push(u);
}
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	memset(uf,-1,sizeof(uf));
	memset(num,0,sizeof(num));
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		s[a].insert(b);
		s[b].insert(a);
		num[a]++;num[b]++;
		int ra=uf_find(a),rb=uf_find(b);
		if(ra!=rb) uf[rb]=ra;
	}
	bool flag=true;
	int num1=0;
	for(int i=1;i<=n;i++) if(uf[i]==-1) num1++;
	if(num1>1) flag=false;
	num1=0;
	if(flag)
	for(int i=1;i<=n;i++) if(num[i]%2) num1++;
	if(num1!=0&&num1!=2||num1==2&&num[1]%2!=1) flag=false;
	if(flag) 
	{
		stack<int> d;
		stack<int> q;
		int u=1;
		d.push(u);
		while(!d.empty())
		{
			u=d.top();
			if(!s[u].empty())
			{
				int v=*(s[u].begin());
				s[u].erase(s[u].begin());
				s[v].erase(u);
				d.push(v);
			}
			else{
				d.pop();
				q.push(u);
			} 
		}
		printf("%d",q.top());
		q.pop();
		while(!q.empty())
		{
			printf(" %d",q.top());
			q.pop();
		}
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}
