#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int num;

// solve(num) : num을 1, 2, 3의 더하기로 나타낼 수 있는 경우의 수
int cache[11];
int solve(int num) {
	if (num == 0)
		return 1;
	if (num < 0)
		return 0;
	int& ret = cache[num];
	if (ret != -1)
		return ret;
	ret = solve(num - 1) + solve(num - 2) + solve(num - 3);
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		memset(cache, -1, sizeof(cache));
		cout << solve(num)<< '\n';
	}
}