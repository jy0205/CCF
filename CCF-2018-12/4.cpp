#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
	edge(int a,int b,int c){
		u = a;v = b;w = c;
	}
};

bool myCompare(const edge &a,const edge &b){
	return a.w < b.w;
}

int uf[50005];
vector<edge> edgeList;

int ufind(int x){
	if(uf[x] == -1)
		return x;
	else
		return uf[x] = ufind(uf[x]);
}

int main(){
	int n,m,root,vi,ui,ti;
	cin >> n >> m >> root;
	for(int i = 1;i <= m;i++){
		cin >> vi >> ui >> ti;
		edgeList.push_back(edge(vi,ui,ti));
	}
	sort(edgeList.begin(),edgeList.end(),myCompare);
	memset(uf,-1,sizeof(uf));
	int num = 0,min_num = -1;
	for(int i = 0;i < m;i++){
		int u = edgeList[i].u;
		int v = edgeList[i].v;
		int w = edgeList[i].w;
		int t1 = ufind(u);
		int t2 = ufind(v);
		if(t1 != t2){
			uf[t1] = t2;
			num++;
			if(w > min_num)
				min_num = w;
		}
		if(num == n - 1)
			break;
	}
	cout << min_num << endl;
	return 0;
}
