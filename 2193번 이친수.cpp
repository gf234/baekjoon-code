#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

// prev : ������ �� ����
// pos : ���ؾ� �ϴ� ��ġ ( 0���� �� )
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