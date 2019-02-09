#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
	int v;
	vector<int> connect;
};

node Map[1005];
int now;
bool visit[1005];
bool cnt[1005][1005];

void dfs(int x){
	cnt[now][x] = true;
	cnt[x][now] = true;
	visit[x] = true;
	for(int i = 0;i < Map[x].connect.size();i++){
		int v = Map[x].connect[i];
		if(visit[v] == false){
			dfs(v);
		}
	}
}

int main(){
	int N,M,a,b;
	cin >> N >> M;
	for(int i = 1;i <= N;i++){
		Map[i].v = i;
	}
	for(int i = 1;i <= M;i++){
		cin >> a >> b;
		Map[a].connect.push_back(b);
	}
	for(int i = 1;i <= N;i++){
		memset(visit,false,sizeof(visit));
		now = i;
		dfs(i);
	}
	int ans = 0;
	for(int i = 1;i <= N;i++){
		if(count(begin(cnt[i]),end(cnt[i]),true) == N)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
