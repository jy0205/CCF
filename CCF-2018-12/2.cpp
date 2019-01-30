#include <iostream>

using namespace std;

int main(){
	int r,y,g,n,k,t;
	long long sum = 0,remain;  //×ÜÊ±¼ä 
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
				remain = sum % (r + y + g);
				if(remain < t)
					sum += t - remain;
				else if(remain >= t && remain <= t + g)
					sum += 0;
				else
					sum += (r + y) - (remain - (t + g));
				break;
			}
			case 2:{
				remain = sum % (r + y + g);
				if(remain < t + r)
					sum += t + r - remain;
				else if(remain >= t + r && remain <= t + r + g)
					sum += 0;
				else
					sum += (r + y) - (remain - (t + r + g));
				break;
			}
			case 3:{
				remain = sum % (r + y + g);
				if(remain < t)
					sum += 0;
				else if(remain >=t && remain <= t + r + y)
					sum += (r + y) - (remain - t);
				else
					sum += 0;
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
