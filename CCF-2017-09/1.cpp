#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int five,three,one;
	five = N / 50;
	N = N % 50;
	three = N / 30;
	N = N % 30;
	one = N / 10;
	int sum = five * 7 + three * 4 + one;
	cout << sum << endl; 
	return 0;
}
