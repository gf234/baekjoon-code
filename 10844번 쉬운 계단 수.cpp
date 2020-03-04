#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int DIV = 1000000000;
int n;

// prevNum : 이전에 나온 숫자
// pos : 현재 위치
int cache[11][101];
int solve(int prevNum, int pos) {
	if (pos == n)
		return 1;

	int& ret = cache[prevNum][pos];
	if (ret != -1)
		return ret;

	if (prevNum == 0)
		ret = solve(1, pos + 1);
	else if (prevNum == 9)
		ret = solve(8, pos + 1);
	else
		ret = solve(prevNum - 1, pos + 1) + solve(prevNum + 1, pos + 1);
	return ret % DIV;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	int ret = 0;
	for (int i = 1; i < 10; ++i) {
		ret = (ret + solve(i, 1)) % DIV;
	}
	cout << ret << "\n";
}