#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

// map : �� ����
int m, n;
int map[500][500];

// �����¿�
int px[] = { -1,1,0,0 };
int py[] = { 0,0,-1,1 };

// ��ǥ�� �ʾȿ� �ִ��� Ȯ��
bool is_correct_position(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return false;
	return true;
}

// x,y��ǥ���� m,n�� ������ �� �ִ� ����� ��
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