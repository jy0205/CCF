#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int R,C;
vector<string> M;
vector<vector<pair<int,int>>> status;
int dir[10][3] = {{-1,0},{1,0},{0,-1},{0,1}};   //代表上、下、左 、右
int bit[60][60];
bool if_arrive;


bool in_map(int x,int y){
	if(x >=0 && x < R && y >=0 && y < C)
		return true;
	else
		return false;
}

void start_BFS(int x,int y){         //找到所有从起点可以到达的点 
	bit[x][y] = 1;
	status[x][y].first = 1;
	if(M[x][y] == 'T'){
		if_arrive = true;
	}
	if(M[x][y] == 'S' || M[x][y] == 'T' || M[x][y] == '+'){
		for(int i = 0;i < 4;i++){
			if(in_map(x+dir[i][0],y+dir[i][1]) && M[x+dir[i][0]][y+dir[i][1]] != '#' && bit[x+dir[i][0]][y+dir[i][1]] == 0){
				start_BFS(x+dir[i][0],y+dir[i][1]);
			}
		} 
	}
	else if(M[x][y] == '-'){
		for(int i = 2;i < 4;i++){
			if(in_map(x+dir[i][0],y+dir[i][1]) && M[x+dir[i][0]][y+dir[i][1]] != '#' && bit[x+dir[i][0]][y+dir[i][1]] == 0){
				start_BFS(x+dir[i][0],y+dir[i][1]);
			}
		} 
	}
	else if(M[x][y] == '|'){
		for(int i = 0;i < 2;i++){
			if(in_map(x+dir[i][0],y+dir[i][1]) && M[x+dir[i][0]][y+dir[i][1]] != '#' && bit[x+dir[i][0]][y+dir[i][1]] == 0){
				start_BFS(x+dir[i][0],y+dir[i][1]);
			}
		} 
	}
	else if(M[x][y] == '.'){
		if(in_map(x+dir[1][0],y+dir[1][1]) && M[x+dir[1][0]][y+dir[1][1]] != '#' && bit[x+dir[1][0]][y+dir[1][1]] == 0){
			start_BFS(x+dir[1][0],y+dir[1][1]);
		}
	}
}

int main(){
	int start_x,start_y,end_x,end_y;
	int result = 0,loc;
	string line;vector<pair<int,int>> line_point;
	cin >> R >> C;
	for(int i = 0;i < R;i++){
		cin >> line;
		M.push_back(line);
		line_point.clear();
		for(int j = 0;j < C;j++){
			line_point.push_back(make_pair(0,0));
			if(line[j] == 'S'){
				start_x = i;start_y = j;
			}
			else if(line[j] == 'T'){
				end_x = i;end_y = j;
			}
			else if(line[j] == '#'){
				line_point[j].first = -1;
				line_point[j].second = -1;
			}
		}
		status.push_back(line_point);
	}
	if_arrive = false;
	start_BFS(start_x,start_y);
	if(!if_arrive)
		cout << "I'm stuck!" << endl;
	else{
		for(int i = 0;i < R;i++){
			for(int j = 0;j < C;j++){
				if(status[i][j].first == 1){
					if(status[i][j].second == 0){
						if_arrive = false;
						memset(bit, 0, sizeof(bit));
						start_BFS(i,j);
						if(if_arrive){
							status[i][j].second = 1;
						}
					}
				}
			}
		}
		for(int i = 0;i < R;i++){
			for(int j = 0;j < C;j++){
				if(status[i][j].first == 1){
					if(status[i][j].second == 0){
						result++;
					}
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}

