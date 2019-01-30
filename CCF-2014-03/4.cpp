#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

const int N = 205;
const int M = 105;

typedef struct{
	int v;
	set<int> connect;        //保存和v相连的点 
}point;

struct node{
	int p,d,k;
	node(int a,int b,int c){
		p = a;
		d = b;
		k = c;
	}
	bool operator < (const node &u) const{
		return d > u.d;
	}
};

point Map[N];
double x[N],y[N];
int dis[N][M];

int main(){
	int n,m,k,cap = 0;
	double r;
	cin >> n >> m >> k >> r;
	for(int i = 0;i < n + m;i++){
		Map[i].v = i;
		cin >> x[i] >> y[i];
		cap++;
		for(int j = 0;j < cap - 1;j++){
			double d = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
			if(d <= r){
				Map[i].connect.insert(j);
				Map[j].connect.insert(i);
			}
		}
	}
	priority_queue<node> q;
	q.push(node(0,0,0));
	memset(dis,999999,sizeof(dis));
	memset(dis[0],0,sizeof(dis[0]));
	while(!q.empty()){
		node temp = q.top();
		q.pop();
		auto iter = Map[temp.p].connect.begin();
		while(iter != Map[temp.p].connect.end()){
			int to = *iter;
			int vd = temp.d + 1,vk = temp.k;
			if(to >= n)
				vk++;
			if(vk > k){
				iter++;
				continue;
			}
			if(dis[to][vk] > vd){
				dis[to][vk] = vd;
				q.push(node(to,vd,vk));
			}
			iter++;
		}
	}
	int min = 999999;
	for(int i = 0;i < M;i++)
		min = (min < dis[1][i])?min:dis[1][i];
	cout << min - 1 << endl;
	return 0;
}
