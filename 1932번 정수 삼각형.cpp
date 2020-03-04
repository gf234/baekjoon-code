#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int tri[500][500];

// prevCol : ÀÌÀü¿¡ °ñ¶ú´ø ¿­
// curRow : ÇöÀç Çà
int cache[501][501];
int solve(int curRow, int prevCol) {
	if (curRow == n)
		return 0;

	int& ret = cache[curRow][prevCol];
	if (ret != -1)
		return ret;

	ret = max(solve(curRow + 1, prevCol) + tri[curRow][prevCol], solve(curRow + 1, prevCol + 1) + tri[curRow][prevCol+1]);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i+1; ++j) {
			cin >> tri[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << solve(0, 0) << "\n";
}