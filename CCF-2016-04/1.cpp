#include <iostream>
using namespace std;

int a[1005];

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1;i < n - 1;i++){
		if(a[i] > a[i-1] && a[i] > a[i+1])
			ans++;
		else if(a[i] < a[i-1] && a[i] < a[i+1])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
