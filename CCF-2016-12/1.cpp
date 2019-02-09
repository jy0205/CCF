#include <iostream>
using namespace std;

int al[1005];

int main(){
	int n,a,b,ans = -1;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> al[i];
	for(int i = 0;i < n;i++){
		a = 0;b = 0;
		for(int j = 0;j < n;j++){
			if(al[j] > al[i])
				a++;
			if(al[j] < al[i])
				b++;
		}
		if(a == b)
			ans = al[i];
	}
	if(ans != -1)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}
