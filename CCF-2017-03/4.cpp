#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct node{
	int v;
	vector<pair<int,int>> connect;
};

node Map[100005];
int cost[100005];
int n,m,a,b,c;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		Map[i].v = i;
	for(int i = 1;i <= m;i++){
		cin >> a >> b >> c;
		Map[a].connect.push_back(make_pair(b,c));
		Map[b].connect.push_back(make_pair(a,c));
	}
	memset(cost,-1,sizeof(cost));
	queue<int> q;
	q.push(1);
	cost[1] = 0;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int i = 0;i < Map[temp].connect.size();i++){
			int v = Map[temp].connect[i].first;
			int d = Map[temp].connect[i].second;
			if(cost[v] == -1 || cost[v] > max(cost[temp],d)){
				cost[v] = max(cost[temp],d);
				q.push(v);
			}
		}
	}
	cout << cost[n] << endl;
	return 0;
}
