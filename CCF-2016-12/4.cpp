#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1005],sum[1005];
int dp[1005][1005];

int main(){
	int n;
	memset(dp,999999,sizeof(dp));
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
		dp[i][i] = 0;
	}
	for(int len = 2;len <= n;len++){
		for(int i = 1;i + len - 1 <= n;i++){
			int j = i + len - 1;
			for(int k = i;k < j;k++){
				int val = dp[i][k] + dp[k+1][j] + sum[j] - sum[i - 1];
				if(val < dp[i][j])
					dp[i][j] = val;
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
