#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
int map[1001][1001];

// solve(r, c) : r,c 에서 출발해서 얻을 수 있는 사탕의 최대 개수
int cache[1001][1001];
int solve(int r, int c) {
	// 맵을 넘어가는 경우 제외
	if (r == n || c == m)
		return 0;

	int& ret = cache[r][c];
	if (ret != -1)
		return ret;

	ret = map[r][c] + max(solve(r + 1, c), solve(r, c + 1));
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(cache, -1, sizeof(cache));

	int result = solve(0, 0);
	cout << result << '\n';
}