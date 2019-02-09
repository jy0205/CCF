#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,ans = 0;
	string num;
	cin >> n;
	num = to_string(n);
	for(int i = 0;i < num.size();i++)
		ans += num[i] - '0';
	cout << ans << endl;
	return 0;
}
