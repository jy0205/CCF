/*Prim算法实现,80分，最后会爆时间*/ 
#include <iostream>
#include <cstring>
#include <list>
using namespace std;

const int N = 1005;

int Map[N][N];

int main(){
	int n,m,x,y,w;
	cin >> n >> m;
	memset(Map,-1,sizeof(Map));
	for(int i = 0;i < m;i++){
		cin >> x >> y >> w;
		Map[x][y] = Map[y][x] = w;
	}
	list<int> in,notin;
	in.push_back(1);
	for(int i = 2;i <= n;i++)
		notin.push_back(i);
	int ans = 0;
	while(!notin.empty()){
		int min_dis = 999999;
		list<int>::iterator point_index;
		auto iter = notin.begin();
		while(iter != notin.end()){
			auto iter_1 = in.begin();
			while(iter_1 != in.end()){
				if(Map[*iter][*iter_1] != -1){
					if(Map[*iter][*iter_1] < min_dis){
						min_dis = Map[*iter][*iter_1];
						point_index = iter;
					}
				}
				iter_1++;	
			}
			iter++;
		}
		ans += min_dis;
		in.push_back(*point_index);
		notin.erase(point_index);
	}
	cout << ans << endl;
	return 0;
}
