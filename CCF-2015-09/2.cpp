#include <iostream>
using namespace std;

int days_1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days_2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

bool if_run(int x){
	if(x % 100 == 0){
		if(x % 400 == 0)
			return true;
		else
			return false;
	}
	else{
		if(x % 4 == 0)
			return true;
		else
			return false;
	}
}

int main(){
	int y,d,days = 0;
	bool flag = false;
	cin >> y >> d;
	if(if_run(y)){
		for(int i = 1;i <= 12;i++){
			for(int j = 1;j <= days_2[i - 1];j++){
				days++;
				if(days == d){
					flag = true;
					cout << i << endl;
					cout << j << endl;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	else{
		for(int i = 1;i <= 12;i++){
			for(int j = 1;j <= days_1[i - 1];j++){
				days++;
				if(days == d){
					flag = true;
					cout << i << endl;
					cout << j << endl;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	return 0;
}
