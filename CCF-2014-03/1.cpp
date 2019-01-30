#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N,n,count = 0;
	vector<int> num;
	cin >> N;
	for(int i = 0;i < N;i++){
		cin >> n;
		num.push_back(n);
	}
	for(int i = 0;i < N;i++){
		for(int j = i+1;j < N;j++){
			if(num[j] == -num[i])
				count++;
		}
	}
	cout << count << endl;
}
