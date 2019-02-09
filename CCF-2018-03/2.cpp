#include <iostream>
using namespace std;

int a[105],v[105];

int main(){
	int n,L,t;
	cin >> n >> L >> t;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == L)
			v[i] = -1;
		else
			v[i] = 1;
	}
	for(int i = 1;i <= t;i++){
		for(int j = 1;j <= n;j++){
			a[j] += v[j];
			if(a[j] == 0 || a[j] == L)
				v[j] = -v[j];
		}
		for(int j = 1;j <= n;j++){
			for(int k = j + 1;k <= n;k++){
				if(a[j] == a[k]){
					v[k] = -v[k];
					v[j] = -v[j];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
