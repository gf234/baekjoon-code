#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#include <limits>
using namespace std;

int n, m;

// ������ ���ϴ� �Լ�
int cache[31][31];
int solve(int n, int r) {
	if (r == 0)
		return 1;
	if (r == 1)
		return n;
	if (r == n)
		return 1;

	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	// *****���� ���� nCr = n-1Cr-1 + n-1Cr*****
	ret = solve(n - 1, r - 1) + solve(n - 1, r);
	return ret;
}

int main() {
	int t;
	cin >> t;
	memset(cache, -1, sizeof(cache));
	for (int tN = 1; tN <= t; ++tN) {
		cin >> n >> m;
		cout << solve(m, n) << '\n';
	}
	return 0;
}