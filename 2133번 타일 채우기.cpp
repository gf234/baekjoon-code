#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;

// solve(n) : 3xN을 채우는 경우의 수
int cache[31];
int solve(int n) {
	// n이 홀수인 경우 채울 수 없다.
	if (n % 2 == 1)
		return 0;
	if (n == 0)
		return 1;
	if (n == 2)
		return 3;

	int& ret = cache[n];
	if (ret != -1)
		return ret;
	
	ret = solve(n - 2) * 3;
	for (int i = 4; i <= n; i = i+2) {
		// 4부터 새로운 경우가 2개씩 생긴다.
		ret += solve(n - i) * 2;
	}
	return ret;
}

int main() {
	cin >> n;

	memset(cache, -1, sizeof(cache));

	int result = solve(n);
	cout << result << '\n';
}