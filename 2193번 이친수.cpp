#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

// prev : 이전에 온 숫자
// pos : 정해야 하는 위치 ( 0부터 셈 )
long long cache[3][91];
long long solve(int prev, int pos) {
	if (pos == n)
		return 1;

	long long& ret = cache[prev][pos];
	if (ret != -1)
		return ret;

	if (prev == 1)
		ret = solve(0, pos + 1);
	else
		ret = solve(0, pos + 1) + solve(1, pos + 1);
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(1, 1) << "\n";
}