#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

long long DIV = 10007;
int n;

// pos : ���� ���� ������ ���� ��ġ ( 0���� ���� )
// prev : ������ �־��� ��
long long cache[1001][10];
long long solve(int pos, int prev) {
	if (pos == n)
		return 1;
	long long& ret = cache[pos][prev];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = prev; i < 10; i++) {
		ret = (ret % DIV) + (solve(pos + 1, i) % DIV);
	}
	return ret;
}

int main() {
	cin >> n;

	memset(cache, -1, sizeof(cache));

	long long result = solve(0, 0);
	cout << result % DIV << '\n';
}