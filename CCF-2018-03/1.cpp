#include <iostream>
using namespace std;

int main(){
	int num,score = 0,last = 1;
	while(1){
		cin >> num;
		if(num == 1){
			score += 1;
			last = 1;
		}
		else if(num == 2){
			if(last == 1){
				score += 2;
				last = 2;
			}
			else{
				score += last + 2;
				last += 2;
			}
		}
		else
			break;
	}
	cout << score << endl;
	return 0;
}
