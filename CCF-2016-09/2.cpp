#include <iostream>
using namespace std;

int a[110],b[110];

int have_nei(int n){
	int start;
	for(int i = 1;i <= 100;i = i + 5){
		for(int j = i;j <= i + 4;j++){
			if(b[j] == 0){
				start = j;
				if(i + 4 - start + 1 >= n)
					return start;
			}
		}
		
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		int sale = a[i],ans;
		ans = have_nei(sale);
		if(ans != -1){
			for(int j = 0;j < sale;j++){
				cout << ans + j << " ";
				b[ans+j] = 1;
			}
			cout << endl;
		}
		else{
			ans = 0;
			for(int j = 1;j <= 100;j++){
				if(b[j] == 0){
					cout << j << " ";
					b[j] = 1;
					ans++;
				}
				if(ans == sale){
					cout << endl;
					break;
				}
			}
		}
	}
	
	return 0;
}
