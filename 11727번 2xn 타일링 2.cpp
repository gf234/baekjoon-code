#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;


long long cache[1001];
long long solve(int num) {
	if (num <= 0)
		return 0;
	if (num == 1)
		return 1;
	if (num == 2)
		return 3;

	long long& ret = cache[num];
	if (ret != -1)
		return ret;

	ret = (solve(num - 1) + solve(num - 2) * 2) % 10007;
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(n) << "\n";
}