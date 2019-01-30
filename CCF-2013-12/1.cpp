#include <iostream>
#include <map>

using namespace std;

int main(){
	int n,num,max = -1,max_num;
	map<int,int> a;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		++a[num];
	}
	auto iter = a.begin();
	while(iter != a.end()){
		if(iter -> second > max){
			max = iter -> second;
			max_num = iter -> first;
		}
		iter++;
	}
	cout << max_num << endl;
	return 0;
}
