#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int cost[1001][3];

// num : 현재까지 칠한 갯수
// prev : 이전에 칠한 색
int cache[1001][4];
int solve(int num, int prev) {
	// 다 칠한 경우
	if (num == n) 
		return 0;
	
	int& ret = cache[num][prev];
	if (ret != -1)
		return ret;

	ret = 987654321;
	for (int i = 0; i < 3; ++i) {
		// 이전에 골랐던 색은 제외
		if (i == prev)
			continue;
		ret = min(ret, solve(num+1, i) + cost[num][i]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> cost[i][j];
		}
	}
	
	memset(cache, -1, sizeof(cache));
	// 처음에 안겹치게 하려고 의미없는 3 입력
	int result = solve(0, 3);
	cout << result << "\n";
}