#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int n,num;
	vector<int> q;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		q.push_back(num);
	}
	sort(q.begin(),q.end());
	int min = 999999;
	for(int i = 0;i < n - 1;i++){
		if(abs(q[i] - q[i+1]) < min)
			min = abs(q[i] - q[i+1]);
	}
	cout << min << endl;
	return 0;
}
