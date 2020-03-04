#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int cost[1001][3];

// num : ������� ĥ�� ����
// prev : ������ ĥ�� ��
int cache[1001][4];
int solve(int num, int prev) {
	// �� ĥ�� ���
	if (num == n) 
		return 0;
	
	int& ret = cache[num][prev];
	if (ret != -1)
		return ret;

	ret = 987654321;
	for (int i = 0; i < 3; ++i) {
		// ������ ����� ���� ����
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
	// ó���� �Ȱ�ġ�� �Ϸ��� �ǹ̾��� 3 �Է�
	int result = solve(0, 3);
	cout << result << "\n";
}