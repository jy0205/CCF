#include <iostream>
#include <set>
#include <map>
using namespace std;

struct node{
	int x;
	int y;
	node(int a,int b){
		x = a;y = b;
	}
	bool operator < (const node &u) const{
		if(y == u.y)
			return x < u.x;
		else
			return y > u.y;
	}
};

int main(){
	int n,num;
	map<int,int> list;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		list[num]++;
	}
	set<node> ans;
	auto iter = list.begin();
	while(iter != list.end()){
		ans.insert(node(iter->first,iter->second));
		iter++;
	}
	for(auto i:ans)
		cout << i.x << " " << i.y << endl;
	return 0;
}
