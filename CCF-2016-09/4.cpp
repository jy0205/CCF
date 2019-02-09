#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct node{
	int v;
	vector<pair<int,int>> connect;
};

struct point{
	int dis;
	int v;
	point(int a,int b){
		v = a;dis = b;
	}
	bool operator < (const point &u) const{
		return dis > u.dis;
	}
};

node Map[10005];
int dist[10005],cost[10005];

int main(){
	int n,m,a,b,c;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		Map[i].v = i + 1;
	for(int i = 0;i < m;i++){
		cin >> a >> b >> c;
		Map[a].connect.push_back(make_pair(b,c));
		Map[b].connect.push_back(make_pair(a,c));
	}
	memset(dist,999999,sizeof(dist));
	memset(cost,999999,sizeof(cost));
	priority_queue<point> q;
	q.push(point(1,0));
	dist[1] = cost[1] = 0;
	while(!q.empty()){
		point temp = q.top();
		q.pop();
		auto iter = Map[temp.v].connect.begin();
		while(iter != Map[temp.v].connect.end()){
			int to = iter -> first;
			int vd = temp.dis + iter -> second;
			if(dist[to] > vd){
				dist[to] = vd;
				cost[to] = iter -> second;
				q.push(point(to,vd));
			}
			else if(dist[to] == vd){
				if(cost[to] > iter -> second){
					cost[to] = iter -> second;
				}
			}
			iter++;
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
		ans += cost[i];
	cout << ans << endl;
	return 0;
}
