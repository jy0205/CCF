#include <iostream>
#include <algorithm>
#include<cstdlib>
using namespace std;

int n;
int a[305],ori[305];
bool flag;

bool satisfy(){
	int num;
	for(int i = 1;i <= n;i++){
		if(ori[i] < 1)
			return false;
		if(i == 1)
			num = (ori[i] + ori[i+1]) / 2;
		else if(i == n)
			num = (ori[i-1] + ori[i]) / 2;
		else
			num = (ori[i] + ori[i-1] + ori[i+1]) / 3;
		if(num != a[i])
			return false;
	}
	return true;
}

void dfs(int index){ 
	if(index == n + 1){
		if(satisfy()){
			flag = true;
			for(int i = 1;i <= n;i++)
				cout << ori[i] << " ";
			cout << endl;
			exit(0);
		}
	}
	else{
		if(index == 2){
			int min_num = a[index - 1] * 2;
			int max_num = (a[index-1] + 1) * 2 - 1;
			int start = min_num - ori[index-1];
			int end = max_num - ori[index-1];
			min_num = a[index] * 3;
			max_num = (a[index] + 1)*3 - 1;
			start = max(start,1);
			end = min(end,max_num - ori[index-1] - 1);
			if(end < 1)
				return;
			for(int i = start;i <= end;i++){
				if(flag)
					break;
				else{
					ori[index] =  i;
					dfs(index+1);
				}
			}
		}
		else if(index == n){
			int min_num = a[index-1] * 3;
			int max_num = (a[index-1] + 1) * 3 - 1;
			int start = min_num - ori[index-1] - ori[index - 2];
			int end = max_num - ori[index-1] - ori[index - 2];
			min_num = a[index] * 2;
			max_num = (a[index] + 1) * 2 - 1;
			start = max(start,min_num - ori[index-1]);
			end = min(end,max_num - ori[index-1]);
			if(end < 1)
				return;
			for(int i = start;i <= end;i++){
				if(flag)
					break;
				else{
					ori[index] =  i;
					if((ori[index] + ori[index - 1] + ori[index - 2]) / 3 == a[index - 1])
						dfs(index+1);
				}
			}
		}
		else{
			int min_num = a[index-1] * 3;
			int max_num = (a[index-1] + 1) * 3 - 1;
			int start = min_num - ori[index-1] - ori[index - 2];
			int end = max_num - ori[index-1] - ori[index - 2];
			min_num = a[index] * 3;
			max_num = (a[index] + 1) * 3 - 1;
			start = max(start,1);
			end = min(end,max_num - ori[index-1] - 1);
			if(end < 1)
				return;
			for(int i = start;i <= end;i++){
				if(flag)
					break;
				else{
					ori[index] =  i;
					if((ori[index] + ori[index - 1] + ori[index - 2]) / 3 == a[index - 1])
						dfs(index+1);
				}
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	flag = false;
	int max_num = 2 * (a[1] + 1) - 1;
	for(int i = 1;i <= max_num - 1;i++){
		if(!flag){
			ori[1] = i;
			dfs(2);
		}
	}
	return 0;
}
