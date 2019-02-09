#include <iostream>
#include <vector>
using namespace std;

int map[20][20];
int moudle[10][10];

vector<pair<int,int>> shape;

int main(){
	int start;
	for(int i = 1;i <= 15;i++)
		for(int j = 1;j <= 10;j++)
			cin >> map[i][j];
	for(int i = 1;i <= 4;i++)
		for(int j = 1;j <= 4;j++)
			cin >> moudle[i][j];
	cin >> start;
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			if(moudle[i][j] == 1)
				shape.push_back(make_pair(i,j));
		}
	}
	bool touch = false;
	for(int i = 0;;i++){
		touch = false;
		for(int j = 0;j < shape.size();j++){
			int x = i + shape[j].first;
			int y = start + shape[j].second - 1;
			if(x + 1 > 15 || map[x+1][y] == 1)
				touch = true;
		}
		if(touch){
			for(int j = 0;j < shape.size();j++){
				int x = i + shape[j].first;
				int y = start + shape[j].second - 1;
				map[x][y] = 1;
			}
			break;
		}
	}
	for(int i = 1;i <= 15;i++){
		for(int j = 1;j <= 10;j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
