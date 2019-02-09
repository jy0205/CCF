#include <iostream>
#include <list>
using namespace std;

int main(){
	int n,k;
	list<int> q;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		q.push_back(i);
	int cnt = 0;
	auto iter = q.begin();
	while(q.size() != 1){
		cnt++;
		if(cnt % k == 0 || cnt % 10 == k){
			iter = q.erase(iter);
		}
		else{
			iter++;
		}
		if(iter == q.end())
			iter = q.begin();
	}
	cout << q.front() << endl;
	return 0;
}
