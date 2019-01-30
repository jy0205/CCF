#include <iostream>
using namespace std;

const int N = 503;

int rect[N][N]; 

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> rect[i][j];
		}
	}
	int incline = 1,i,j;
	while(incline <= 2 * n - 1){
		if(incline % 2 != 0){
			i = (incline <= n)?incline:n;
			j = (incline <= n)?1:(incline - n + 1);
			while(i >= 1 && j <= n){
				cout << rect[i][j] << " ";
				i--;j++;
			}
		}
		else{
			i = (incline <= n)?1:(incline - n + 1);
			j = (incline <= n)?incline:n;
			while(j >= 1 && i <= n){
				cout << rect[i][j] << " ";
				j--;i++;
			}
		}
		incline++;
	}
	return 0;
}
