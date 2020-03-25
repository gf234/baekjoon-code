#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int A[1001];

// pos : 현재 위치
int cache[1001];
int solve(int pos) {
	if (pos == n)
		return 0;

	int& ret = cache[pos];
	if (ret != -1)
		return ret;

	ret = A[pos];
	for (int i = pos + 1; i <= n; ++i) 
		if(A[pos] < A[i])
			ret = max(ret, A[pos] + solve(i));
	
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	A[n] = 987654321;
	memset(cache, -1, sizeof(cache));

	int result = 1;
	for (int i = 0; i < n; ++i) {
		result = max(result, solve(i));
	}

	cout << result << '\n';
}