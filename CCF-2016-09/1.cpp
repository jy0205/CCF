#include <iostream>
#include <cmath>
using namespace std;

int a[1005];

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	int max_num = -1;
	for(int i = 1;i < n;i++){
		int now = abs(a[i] - a[i-1]);
		if(now > max_num)
			max_num = now;
	}
	cout << max_num << endl;
	return 0;
} 
