#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

// n : 채워야하는 타일의 수
int cache[1001];
int solve(int n) {
	if (n < 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	int& ret = cache[n];
	if (ret != -1)
		return ret;

	ret = solve(n - 1) + solve(n - 2);
	return ret % 10007;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(n) << "\n";
}