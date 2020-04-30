#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <climits>
using namespace std;

int n;
int chapters[501];
// psum[i] : 1~i 까지의 부분합
int psum[501];
// dp[i][j] : i~j까지 합치는 데 드는 최소한의 비용.
// -> dp[i][i] = chapters[i], dp[i][i+1] = chapters[i] + chapters[i+1]
// k : 두 그룹으로 나누는 기준이 되는 수
// dp[i][j] = min(i<=k<j){dp[i][k] + dp[k+1][j]} + psum[i][j](psum[i][j]는 chapters의 i~j까지의 부분합)
int dp[501][501];

int main()
{
	int t;
	cin >> t;
	for (int testCase = 1; testCase <= t; ++testCase)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> chapters[i];
			psum[i] = psum[i - 1] + chapters[i];
		}

		for (int distance = 1; distance < n; ++distance)
		{
			for (int i = 1; i + distance <= n; ++i)
			{
				int j = i + distance;
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; ++k)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + psum[j] - psum[i - 1]);
				}
			}
		}
		cout << dp[1][n] << '\n';
	}
	return 0;
}
