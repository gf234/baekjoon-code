#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#include <limits>
using namespace std;

int n;
int T[15], P[15];

// solve(day) : day~n까지 얻을 수 있는 최대값
int cache[15];
int solve(int day) {
	if (day > n)
		return -987654321;
	if (day == n)
		return 0;

	int& ret = cache[day];
	if (ret != -1)
		return ret;

	ret = max(P[day] + solve(day + T[day]), solve(day + 1));

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> T[i] >> P[i];
	}
	memset(cache, -1, sizeof(cache));

	cout << solve(0) << '\n';
}