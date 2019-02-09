#include <iostream>
using namespace std;

int caltax(int n){
	int num;
	if(n <= 3500)
		return 0;
	else{
		num = n - 3500;
		if(num <= 1500)
			return num/100*3;
		else if(num > 1500 && num <= 4500)
			return (45 + (num - 1500)/100*10);
		else if(num > 4500 && num <= 9000)
			return (45 + 300 + (num - 4500)/100*20);
		else if(num > 9000 && num <= 35000)
			return (45 + 300 + 900 + (num - 9000)/100*25);
		else if(num > 35000 && num <= 55000)
			return (45 + 300 + 900 + 6500 + (num - 35000)/100*30);
		else if(num > 55000 && num <= 80000)
			return (45 + 300 + 900 + 6500 + 6000 + (num - 55000)/100*35);
		else
			return (45 + 300 + 900 + 6500 + 6000 + 8750 + (num - 80000)/100*45);
	}
}

int main(){
	int T,S;
	cin >> T;
	int start = T/100*100;
	if(start < T)
		start += 100;
	
	for(int i = start;;i = i + 100){
		int tax = caltax(i);
		int remain = i - tax;
		if(remain == T){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
