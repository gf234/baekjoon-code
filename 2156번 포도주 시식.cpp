#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int amount[10001];

// pos : 현재 위치
// cnt : 연속으로 마신 수
int cache[10001][4];
int solve(int pos, int cnt) {
	if (pos == n)
		return 0;

	int& ret = cache[pos][cnt];
	if (ret != -1)
		return ret;
	
	// 2개를 연속으로 마신경우 마실 수 없음
	if (cnt == 2)
		ret = solve(pos + 1, 0);
	else
		ret = max(solve(pos + 1, cnt + 1) + amount[pos], solve(pos + 1, 0));
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> amount[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << solve(0, 0) << "\n";
}