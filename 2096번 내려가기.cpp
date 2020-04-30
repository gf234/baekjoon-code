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
int map[100000][3];

// 최대 최소를 계산할때 이전층의 정보만 있으면 된다.
vector<vector<int>> dp(2, vector<int>(5));

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}

	// 처음 층을 넣어준다.
	dp[0][1] = map[0][0];
	dp[0][2] = map[0][1];
	dp[0][3] = map[0][2];
	for (int f = 1; f < n; ++f)
	{
		for (int j = 1; j <= 3; ++j)
		{
			dp[1][j] = max(dp[0][j], max(dp[0][j - 1], dp[0][j + 1])) + map[f][j - 1];
		}
		// 밑에 층을 위로 옮겨서 다시 계산한다.
		dp[0] = dp[1];
	}
	int Max = max(dp[0][1], max(dp[0][2], dp[0][3]));

	// 최소값을 구할것이기 때문에 필요 없는 부분을 큰 값으로 채워준다.
	dp.assign(2, vector<int>(5, 987654321));
	dp[0][1] = map[0][0];
	dp[0][2] = map[0][1];
	dp[0][3] = map[0][2];

	for (int f = 1; f < n; ++f)
	{
		for (int j = 1; j <= 3; ++j)
		{
			dp[1][j] = min(dp[0][j], min(dp[0][j - 1], dp[0][j + 1])) + map[f][j - 1];
		}
		dp[0] = dp[1];
	}
	int Min = min(dp[0][1], min(dp[0][2], dp[0][3]));

	cout << Max << " " << Min;

	return 0;
}
