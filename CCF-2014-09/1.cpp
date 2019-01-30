#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int n,num,count = 0;
	vector<int> list;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		list.push_back(num);
	}
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(abs(list[i] - list[j]) == 1)
				count ++;
		}
	}
	cout << count << endl;
	return 0;
} 
