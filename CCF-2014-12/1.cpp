#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	int n,num;
	vector<int> id;
	map<int,int> record;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		id.push_back(num);
	}
	for(int i = 0;i < n;i++){
		record[id[i]]++;
		cout << record[id[i]] << " ";
	}
	return 0;
}
