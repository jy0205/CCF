#include <iostream>
using namespace std;

int main(){
	int n,ans = 0,num,lastnum = -5;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		if(num != lastnum){
			ans++;
			lastnum = num;
		}
	}
	cout << ans << endl;
	return 0;
} 
