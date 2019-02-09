#include <iostream>
#include <vector> 
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10005;

struct node{
	int v;
	vector<int> connect;
};

node Map[N];
int DFN[N],Low[N],tot,stack[N],top = -1;
bool instack[N];
vector<int> graph;     //保存每个强连通图的点的个数 

void tarjan(int x){
	DFN[x] = Low[x] = ++tot;   //tot为时间戳,记录访问的次序 
	stack[++top] = x;       //将x进栈
	instack[x] = true;
	for(int i = 0;i < Map[x].connect.size();i++){
		int v =  Map[x].connect[i];
		if(!DFN[v]){
			tarjan(v);
			Low[x] = min(Low[x],Low[v]);
		}
		else if(instack[v]){
			Low[x] = min(Low[x],DFN[v]);
		}
	}
	if(Low[x] == DFN[x]){
		int num = 0;
		do{
			num++;
			instack[stack[top]] = false;
			top--;
		}while(x != stack[top + 1]);
		graph.push_back(num);
	} 
}

int main(){
	int n,m,a,b;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		Map[i].v = i;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		Map[a].connect.push_back(b);
	}
	memset(instack,false,sizeof(instack));
	for(int i = 1;i <= n;i++){     //Tarjan算法主循环 
		if(!DFN[i])
			tarjan(i);
	}
	int ans = 0;
	for(int i = 0;i < graph.size();i++)
		ans += (graph[i]*(graph[i] - 1))/2;
	cout << ans << endl;
	return 0;
}
