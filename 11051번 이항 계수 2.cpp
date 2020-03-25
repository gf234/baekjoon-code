#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, k;
int DIV = 10007;

// 이항계수 n,k = n-1,k + n-1,k-1 
// k == 0 -> 1
long long cache[1001][1001];
long long solve(int n, int k) {
	if (k < 0 || k > n)
		return 0;
	if (k == 1)
		return n;
	if (k == 0)
		return 1;
	long long& ret = cache[n][k];
	if (ret != -1)
		return ret;

	ret = (solve(n-1,k) % DIV) + (solve(n-1, k-1) % DIV);
	return ret % DIV;
}

int main() {
	cin >> n >> k;
	memset(cache, -1, sizeof(cache));

	long long result = solve(n, k);
	cout << result << '\n';
}