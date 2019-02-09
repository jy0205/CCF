#include <iostream>
using namespace std;

int a[1005],ori[1005];

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> ori[i];
	for(int i = 0;i < n;i++){
		if(i == 0)
			a[i] = (ori[i] + ori[i+1]) / 2;
		else if(i == n - 1)
			a[i] = (ori[i] + ori[i-1]) / 2;
		else
			a[i] = (ori[i] + ori[i-1] + ori[i+1]) / 3;
	}
	for(int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
