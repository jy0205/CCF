#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,h,area = -1,now_area;
	vector<int> height;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> h;
		height.push_back(h);
	}
	for(int i = 0;i < n;i++){
		int min_height = height[i];
		if(min_height > area)
			area = min_height;
		for(int j = i+1;j < n;j++){
			if(height[j] < min_height)
				min_height = height[j];
			now_area = min_height * (j - i + 1);
			if(now_area > area)
				area = now_area;
		}
	}
	cout << area << endl;
	return 0;
}
