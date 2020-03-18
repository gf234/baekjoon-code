#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#include <limits>
using namespace std;

int n, m;

// Ç×»ó n < m
int cache[301][301];
int solve(int n, int m) {
	if (n > m)
		swap(n, m);
	if (n == 1)
		return m - 1;

	int& ret = cache[n][m];
	if (ret != -1)
		return ret;

	ret = 1 + solve(n / 2, m) + solve(n - n / 2, m);
	cache[m][n] = ret;
	return ret;
}

int main() {
	cin >> n >> m;

	memset(cache, -1, sizeof(cache));

	cout << solve(n, m) << '\n';

	return 0;
}