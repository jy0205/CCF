#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct edge{
	int to;
	int len;
	int kind;
};

struct point{
	int v;
	int cost;
	point(int a,int b){
		v = a;cost = b;
	} 
	bool operator < (const point &u) const{
		return cost > u.cost;
	}
};

struct node{
	int v;
	vector<edge> connect;
};

long long small_dis[505],acu_small[505],dis[505];   //small_dis表示到达该点时连续走的小路的距离 
node Map[505];

int main(){
	int n,m,t,a,b,c;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		Map[i].v = i;
	}
	for(int i = 1;i <= m;i++){
		edge temp;
		cin >> t >> a >> b >> c;
		temp.kind = t;
		temp.to = b;
		temp.len = c;
		Map[a].connect.push_back(temp);
		temp.to = a;
		Map[b].connect.push_back(temp);
	}
	memset(dis,999999,sizeof(dis));
	priority_queue<point> q;
	q.push(point(1,0));
	dis[1] = 0;
	while(!q.empty()){
		point temp = q.top();
		q.pop();
		int u = temp.v;
		for(int i = 0;i < Map[u].connect.size();i++){
			int v = Map[u].connect[i].to;
			int len = Map[u].connect[i].len;
			int type = Map[u].connect[i].kind;
			if(type == 1){
				long long num = acu_small[u] + len;
				long long d = dis[u] - small_dis[u] + (num * num);
				if(dis[v] > d){
					dis[v] = d;
					acu_small[v] = num;
					small_dis[v] = num * num;
					q.push(point(v,d));
				}
			}
			else{
				long long d = dis[u] + len;
				if(dis[v] > d){
					dis[v] = d;
					small_dis[v] = 0;
					acu_small[v] = 0;
					q.push(point(v,d));
				}
			}
		}
	}
	cout << dis[n] << endl;
	return 0;
}
