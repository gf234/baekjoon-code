#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int num;
int score[301];

// stairsNum : 현재 밟으려는 계단의 숫자
// cnt : 현재까지 연속으로 밟은 횟수
int cache[301][4];
int solve(int stairsNum, int cnt) {
	if (cnt == 3 || stairsNum > num)
		return 0;

	if (stairsNum == num)
		return score[num];

	int& ret = cache[stairsNum][cnt];
	if (ret != -1)
		return ret;

	// 마지막을 못밟는 경우
	if (stairsNum == (num - 1) && cnt == 2)
		return 0;

	ret = score[stairsNum] + max(solve(stairsNum + 1, cnt + 1), solve(stairsNum + 2, 1));
	return ret;
}

int main() {
	cin >> num;
	score[0] = 0;
	for (int i = 1; i <= num; ++i) {
		int temp;
		cin >> temp;
		score[i] = temp;
	}
	memset(cache, -1, sizeof(cache));
	cout << solve(0, 0) << "\n";
}