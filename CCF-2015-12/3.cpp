#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct node{
	int x;
	int y;
	node(int a,int b){
		x = a;y = b;
	}
};

char canvas[105][105];
bool visit[105][105];
int direct[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main(){
	int m,n,q,kind,x1,y1,x2,y2,x,y;
	char c;
	memset(canvas,'.',sizeof(canvas));
	cin >> m >> n >> q;
	for(int i = 1;i <= q;i++){
		cin >> kind;
		if(kind == 0){
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1 == x2){   //ÊúÏß
				int min = (y1 <= y2)?y1:y2;
				int max = (y1 >= y2)?y1:y2;
				for(int j = min;j <= max;j++){
					if(canvas[j][x1] == '-' || canvas[j][x1] == '+')
						canvas[j][x1] = '+';
					else
						canvas[j][x1] = '|';
				}
			}
			else{
				int min = (x1 <= x2)?x1:x2;
				int max = (x1 >= x2)?x1:x2;
				for(int j = min;j <= max;j++){
					if(canvas[y1][j] == '|' || canvas[y1][j] == '+')
						canvas[y1][j] = '+';
					else
						canvas[y1][j] = '-';
				}
			}
		}
		else{
			scanf("%d %d %c",&x,&y,&c);
			memset(visit,false,sizeof(visit));
			queue<node> q;
			q.push(node(x,y));
			canvas[y][x] = c;
			visit[y][x] = true;
			while(!q.empty()){
				node temp = q.front();
				q.pop();
				for(int i = 0;i < 4;i++){
					int newx = temp.x + direct[i][0];
					int newy = temp.y + direct[i][1];
					if(visit[newy][newx])
						continue;
					if(newx < 0 || newx >= m || newy < 0 || newy >= n)
						continue;
					if(canvas[newy][newx] == '-' || canvas[newy][newx] == '|' || canvas[newy][newx] == '+')
						continue;
					q.push(node(newx,newy));
					visit[newy][newx] = true;
					canvas[newy][newx] = c;
				}
			}
		}
	}
	for(int i = n - 1;i >= 0;i--){
		for(int j = 0;j < m;j++)
			cout << canvas[i][j];
		cout << endl;
	}
	return 0;
}
