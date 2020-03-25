#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, k;
int coinValue[101];

// solve(k) : k를 만들수있는 최소 동전의 수
int cache[10001];
int solve(int k) {
	if (k < 0)
		return 987654321;
	if (k == 0)
		return 0;

	int& ret = cache[k];
	if (ret != -1)
		return ret;

	ret = 987654321;
	for (int i = 0; i < n; ++i) {
		ret = min(ret, solve(k - coinValue[i]) + 1);
	}
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> coinValue[i];
	}
	memset(cache, -1, sizeof(cache));

	int result = solve(k);
	if (result == 987654321)
		cout << -1 << '\n';
	else
		cout << result << '\n';
}