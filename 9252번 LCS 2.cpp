#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <climits>
using namespace std;

string a, b, c;
int dp[1001][1001];

int main()
{
	cin >> a >> b;

	// LCS 알고리즘
	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			// 같은 경우 대각선 왼쪽 위의 값에서 1을 더한다!!!
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int max_len = dp[a.size()][b.size()];
	cout << max_len << '\n';

	// 실제 값 찾기
	// 왼쪽이나 위로 같은 값을 따라 간다.
	// 모두 같은 값이 없으면 대각선으로 이동 + 해당 값이 LCS에 포함된다.
	int i = a.size();
	int j = b.size();
	while (dp[i][j] != 0)
	{
		if (dp[i][j] == dp[i][j - 1])
			--j;
		else if (dp[i][j] == dp[i - 1][j])
			--i;
		else
		{
			c += a[i - 1];
			--i;
			--j;
		}
	}

	// 거꾸로 저장했으므로 뒤집어 준다.
	if (!c.empty())
	{
		reverse(c.begin(), c.end());
		cout << c;
	}
	return 0;
}
