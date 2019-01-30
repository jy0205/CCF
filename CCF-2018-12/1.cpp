#include <iostream>

using namespace std;

int main(){
	int r,y,g,n,k,t;
	int sum = 0;  //×ÜÊ±¼ä 
	cin >> r >> y >> g;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> k >> t;
		switch(k){
			case 0:{
				sum += t;
				break;
			} 
			case 1:{
				sum += t;
				break;
			}
			case 2:{
				sum += t + r;
				break;
			}
			case 3:{
				sum += 0;
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
