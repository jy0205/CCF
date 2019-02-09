#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <stack>
using namespace std;

const int M = 100005;
const int N = 10005;

int n,m;
int uf[N],num[N];

set<int> s[N];
stack<int> path;

void dfs(int u)
{
	while(!s[u].empty())
	{
		int v=*s[u].begin();
		s[u].erase(v);
		s[v].erase(u);
		dfs(v);
	}
	path.push(u);
}


int ufind(int u)
{
	if(uf[u]==-1) return u;
	return uf[u]=ufind(uf[u]);
}

int main(){
	int a,b;
	cin >> n >> m;
	memset(uf,-1,sizeof(uf));
	for(int i = 1;i <= m;i++){
		cin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
		num[a]++;num[b]++;
		int t1 = ufind(a);
		int t2 = ufind(b);
		if(t1 != t2){
			uf[t2] = t1;
		}
	}
	bool flag = true;
	int num1=0;
	for(int i=1;i<=n;i++) 
		if(uf[i]==-1)
			num1++;
	if(num1>1)
		flag=false;
	num1=0;
	if(flag)
	for(int i=1;i<=n;i++) if(num[i]%2) num1++;
	if(num1!=0&&num1!=2||num1==2&&num[1]%2!=1) flag=false;
	if(!flag)
		cout << -1 << endl;
	else{
		dfs(1);
		while(!path.empty())
		{
			cout << path.top() << " ";
			path.pop();
		}
	}
	return 0;
}
