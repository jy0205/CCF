#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
	string isbn;
	int num = 0,count = 0;
	cin >> isbn;
	for(int i = 0;i < isbn.size() - 1;i++){
		if(isdigit(isbn[i])){
			count++;
			num += count * (isbn[i] - '0');
		}
	}
	num %= 11;
	if(num == 10){
		if(isbn[isbn.size() - 1] == 'X')
			cout << "Right" << endl;
		else{
			isbn[isbn.size() - 1] = 'X';
			cout << isbn << endl;
		}
	}
	else{
		if(isbn[isbn.size() - 1] == num + '0')
			cout << "Right" << endl;
		else{
			isbn[isbn.size() - 1] = num + '0';
			cout << isbn << endl;
		}
	}
	return 0;
}
