#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

// map : ������ ��ġ ������ ��Ÿ����.
// seen : Ž�� ���θ� ��Ÿ����.
int map[50][50];
int m, n, k;
int seen[50][50];

//           ��,��,��,��
int px[] = { -1,1,0,0 };
int py[] = { 0,0,-1,1 };

// ��ǥ�� �� �ȿ� �ִ��� �˻��Ѵ�.
bool is_correct_spot(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return false;
	return true;
}

// dfs�� �̿��� ������ִ� �κ��� ��� Ž���Ѵ�.
void dfs(int x, int y) {
	seen[x][y] = 1;
	for (int k = 0; k < 4; ++k) {
		int tempX = x + px[k], tempY = y + py[k];
		if (!(tempX < 0 || tempY < 0 || tempX >= m || tempY >= n) && (map[tempX][tempY] == 1) && seen[tempX][tempY] != 1) {
			dfs(tempX, tempY);
		}
	}
}

// �������ִ� ������Ʈ�� ������ ����.
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