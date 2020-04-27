#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

// map : 배추의 위치 정보를 나타낸다.
// seen : 탐색 여부를 나타낸다.
int map[50][50];
int m, n, k;
int seen[50][50];

//           위,아,왼,오
int px[] = { -1,1,0,0 };
int py[] = { 0,0,-1,1 };

// 좌표가 맵 안에 있는지 검사한다.
bool is_correct_spot(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return false;
	return true;
}

// dfs를 이용해 연결되있는 부분을 모두 탐색한다.
void dfs(int x, int y) {
	seen[x][y] = 1;
	for (int k = 0; k < 4; ++k) {
		int tempX = x + px[k], tempY = y + py[k];
		if (!(tempX < 0 || tempY < 0 || tempX >= m || tempY >= n) && (map[tempX][tempY] == 1) && seen[tempX][tempY] != 1) {
			dfs(tempX, tempY);
		}
	}
}

// 나눠져있는 컴포넌트의 개수를 센다.
int dfsAll() {
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((seen[i][j] != 1) && (map[i][j] == 1)) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int t;
	cin >> t;
	for (int testN = 1; testN <= t; ++testN) {
		memset(map, 0, sizeof(map));
		memset(seen, 0, sizeof(seen));
		cin >> m >> n >> k;

		for (int i = 0; i < k; ++i) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		
		int ret = dfsAll();
		cout << ret << '\n';
	}
}