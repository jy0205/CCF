#include <iostream>
using namespace std;

int a[1005];

int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int ans = 0,sum = 0;
	for(int i = 0;i < n;i++){
		sum += a[i];
		if(sum >= k){
			ans++;
			sum = 0;
		}
	}
	if(sum != 0)
		ans++;
	cout << ans << endl;
	return 0;
} 
