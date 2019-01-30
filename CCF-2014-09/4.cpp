#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1005;

bool arrive[N][N];
int dis[N][N];
int num[N][N];        //给某个点的送餐数量 
int direct[4][3] = {{0,1},{1,0},{0,-1},{-1,0}};
struct node{
	int x;int y;
	node(int a,int b){
		x = a;y = b;
	}
};

int main(){
	int n,m,k,d;
	int x,y,c;
	cin >> n >> m >> k >> d;
	queue<node> q;
	memset(dis,-1,sizeof(dis));
	memset(arrive,true,sizeof(arrive));
	memset(num,0,sizeof(num));
	for(int i = 0;i < m;i++){
		cin >> x >> y;
		q.push(node(x,y));
		dis[x][y] = 0;
	}
	for(int i = 0;i < k;i++){
		cin >> x >> y >> c;
		num[x][y] += c;
	}
	for(int i = 0;i < d;i++){
		cin >> x >> y;
		arrive[x][y] = false;
	}
	//计算从每个分店到达每个点的距离 
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		for(int i = 0;i < 4;i++){
			int nx = temp.x + direct[i][0];
			int ny = temp.y + direct[i][1];
			if(nx < 1 || nx > n || ny < 1 || ny > n)
				continue;
			if(!arrive[nx][ny])
				continue;
			if(dis[nx][ny] != -1)
				continue;
			dis[nx][ny] = dis[temp.x][temp.y] + 1;
			q.push(node(nx,ny));
		}
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			ans += (long long)(dis[i][j]) * (long long)(num[i][j]);
		}
	}
	cout << ans <<endl;
	return 0;
}
