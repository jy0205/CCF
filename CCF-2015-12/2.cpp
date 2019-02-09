#include <iostream>
using namespace std;

int map[50][50];
int ori[50][50];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> map[i][j];
			ori[i][j] = map[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(ori[i][j] != 0){
				int start = ori[i][j],cnt = 0,lnt = 0;
				for(int k = j;k <= m;k++){
					if(ori[i][k] == start)
						cnt++;
					else
						break;
				}
				for(int k = i;k <= n;k++){
					if(ori[k][j] == start)
						lnt++;
					else
						break;
				}
				if(cnt >= 3){
					for(int k = 0;k < cnt;k++)
						map[i][j+k] = 0;
				}
				if(lnt >= 3){
					for(int k = 0;k < lnt;k++)
						map[i+k][j] = 0;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
