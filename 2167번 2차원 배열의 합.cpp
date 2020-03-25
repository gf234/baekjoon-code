#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, k;
int RC[301][301];

// pos : 현재 위치
// calcSum(r, c) : 1,1 ~ r,c 까지의 합을 구하는 함수.
int cache[301][301];
int calcSum(int r, int c) {
	if (r < 1 || c < 1)
		return 0;

	int& ret = cache[r][c];
	if (ret != -1)
		return ret;

	ret = RC[r][c] + calcSum(r - 1, c) + calcSum(r, c - 1) - calcSum(r - 1, c - 1);
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			// cin과 시간차이가 꽤 많이남
			scanf("%d", &RC[i][j]);
	cin >> k;
	for (int c = 0; c < k; ++c) {
		int i, j, x, y;
		scanf("%d%d%d%d", &i, &j, &x, &y);
		int	result = calcSum(x,y) - calcSum(x,j-1) - calcSum(i-1,y) + calcSum(i-1,j-1);
		cout << result << '\n';
	}

}