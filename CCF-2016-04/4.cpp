#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int danger[105][105];
int danger_loc[105][3];
int ll[105][105],lr[105][105];
int direct[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool visit[105][105][500];
int n,m,t,r,c,a,b;

struct node{
	int x;
	int y;
	int t;
	node(int a,int b,int c){
		x = a;y = b;t = c;
	}
};

int bfs(){
	queue<node> q;
	q.push(node(1,1,0));
	visit[1][1][0] = true;
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		for(int i = 0;i < 4;i++){
			int newx = temp.x + direct[i][0];
			int newy = temp.y + direct[i][1];
			int time = temp.t + 1; 
			if(newx < 1 || newx > n || newy < 1 || newy > m)
				continue;
			if(time<=lr[newx][newy]&&time>=ll[newx][newy])
				continue;
			if(visit[newx][newy][time])
				continue;
			if(newx == n && newy == m)
				return time;
			q.push(node(newx,newy,time));
			visit[newx][newy][time] = true;
		}
	}
	return -1;
}

int main(){
	cin >> n >> m >> t;
	memset(danger,-1,sizeof(danger));
	memset(visit,false,sizeof(visit));
	for(int i = 1;i <= t;i++){
		cin >> r >> c >> a >> b;
		ll[r][c] = a;
		lr[r][c] = b;
	}
	cout << bfs() << endl;
	return 0;
}
