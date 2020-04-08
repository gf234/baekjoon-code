#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n;
int A[1001];

// pos : 고를 위치
// before : 전에 골랐던 숫자
int cache[1002][1002];
int solve(int pos, int before) {
	if (pos == n)
		return 0;

	int& ret = cache[pos][before];
	if (ret != -1)
		return ret;

	ret = 0;

	if (A[pos] < before)
		ret = solve(pos + 1, A[pos]) + 1;
	ret = max(ret, solve(pos + 1, before));

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	memset(cache, -1, sizeof(cache));

	int ret = solve(0, 1001);

	cout << ret << '\n';

	return 0;
}