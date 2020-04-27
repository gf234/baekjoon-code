#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

// map : 맵 정보
int m, n;
int map[500][500];

// 상하좌우
int px[] = { -1,1,0,0 };
int py[] = { 0,0,-1,1 };

// 좌표가 맵안에 있는지 확인
bool is_correct_position(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return false;
	return true;
}

// x,y좌표에서 m,n에 도달할 수 있는 경우의 수
int cache[500][500];
int solve(int x, int y) {
	if (x == m - 1 && y == n - 1)
		return 1;

	int& ret = cache[x][y];
	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < 4; ++i) {
		int tx = x + px[i], ty = y + py[i];
		if (is_correct_position(tx, ty) && (map[x][y] > map[tx][ty])) {
			ret += solve(tx, ty);
		}
	}
	return ret;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));

	int ret = solve(0, 0);
	cout << ret << '\n';
}