#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

list<int> queue;

int main(){
	int n,m,p,q;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		queue.push_back(i+1);
	}
	for(int i = 0;i < m;i++){
		cin >> p >> q;
		auto iter = find(queue.begin(),queue.end(),p);
		iter = queue.erase(iter);
		if(q > 0){
			while(q--)
				iter++;
			queue.insert(iter,p);
		}
		else{
			q = -q;
			while(q--)
				iter--;
			queue.insert(iter,p);
		}
	}
	auto iter = queue.begin();
	while(iter != queue.end()){
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
	return 0;
}
