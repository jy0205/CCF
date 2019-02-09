#include <iostream>
using namespace std;

int time[1000005];

int main(){
	int n,a,b,c,d;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a >> b;
		for(int j = a;j < b;j++)
			time[j]++;
	}
	for(int i = 0;i < n;i++){
		cin >> c >> d;
		for(int j = c;j < d;j++)
			time[j]++;
	}
	int ans = 0;
	for(int i = 1;i <= 1000001;i++){
		if(time[i] == 2)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
