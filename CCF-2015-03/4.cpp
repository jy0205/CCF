#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10003;
const int M = 10003;

struct node{
	int v;
	int depth;
	vector<int> connect;
};

node Map[N + M];
bool visit[N + M];
int ans = -1,now_dis = -1;

void dfs(int x){
	visit[x] = true;
	now_dis++;
	if(now_dis > ans)
		ans = now_dis;
	for(int i = 0;i < Map[x].connect.size();i++){
		if(!visit[Map[x].connect[i]])
			dfs(Map[x].connect[i]);
	}
	now_dis--;
}

int main(){
	int n,m,num,max_depth_index = 1,max_depth = 1;
	cin >> n >> m;
	Map[1].v = 1;Map[1].depth = 1;
	for(int i = 2;i <= n + m;i++){
		cin >> num;
		Map[i].v = i;
		Map[i].depth = Map[num].depth + 1;
		if(Map[i].depth > max_depth){
			max_depth = Map[i].depth;
			max_depth_index = i;
		}
		Map[num].connect.push_back(i);
		Map[i].connect.push_back(num);
	}
	memset(visit,false,sizeof(visit));
	dfs(max_depth_index);
	cout << ans << endl;
	return 0;
} 
