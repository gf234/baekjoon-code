#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n;
int DIV = 15746;


int cache[1000001];
// 재귀형식은 너무 오래 걸림
int solve(int pos) {
	if (pos > n)
		return 0;
	if (pos == n)
		return 1;

	int ret = cache[pos];
	if (ret != -1)
		return ret;

	ret = (solve(pos + 1) + solve(pos + 2)) % DIV;
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));

	// 밑에부터 계산하는게 훨씬 빠름
	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 3;
	for (int i = 4; i <= n; ++i) {
		cache[i] = (cache[i - 1] + cache[i - 2]) % DIV;
	}

	cout << cache[n] << '\n';

	return 0;
}