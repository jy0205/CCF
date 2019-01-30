#include <iostream>
using namespace std;

int a[1005][1005];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
		}
	}
	for(int j = m;j >= 1;j--){
		for(int i = 1;i <= n;i++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
