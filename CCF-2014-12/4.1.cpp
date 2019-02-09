#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
const int M = 100005;

struct edge{
	int u;
	int v;
	int w;
};

edge edgeList[M];
int connect[N];

bool myCompare(edge a,edge b){
	return a.w < b.w;
}

int find(int x){
	if(connect[x] == -1)
		return x;
	else
		return connect[x]=find(connect[x]);	
}

int main(){
	int n,m,x,y,c;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> x >> y >> c;
		edgeList[i].u = x;
		edgeList[i].v = y;
		edgeList[i].w = c;
	}
	sort(edgeList,edgeList + m,myCompare);
	int ans = 0,in = 0;
	memset(connect,-1,sizeof(connect));
	for(int i = 0;i < m;i++){
		int u = edgeList[i].u;
		int v = edgeList[i].v;
		int w = edgeList[i].w;
		int t1 = find(u);
		int t2 = find(v);
		if(t1 != t2){
			connect[t1] = t2;
			ans += w;
			in++;
		}
		if(in == n - 1)
			break;
	}
	cout << ans << endl;
	return 0;
} 
