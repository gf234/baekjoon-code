#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;

	// 0으로 첫행, 첫열 채움
	for(int i =0;i<n;++i){
		char temp;
		for(int j = 0; j<m;++j){
			cin >> temp;
			dp[i+1][j+1] = temp-'0';
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (dp[i][j]) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}
	cout << ret*ret;
}
