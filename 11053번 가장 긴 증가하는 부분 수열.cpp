#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int nums[1001];

// pos : 현재 위치
// prevNum : 이전에 가장 큰 숫자
int cache[1001][1001];
int solve(int pos, int prevNum) {
	// 끝까지 가면 리턴
	if (pos == n)
		return 0;

	int& ret = cache[pos][prevNum];
	if (ret != -1)
		return ret;

	if (prevNum < nums[pos])
		ret = max(solve(pos + 1, nums[pos]) + 1, solve(pos+1,prevNum));
	else 
		ret = solve(pos + 1, prevNum);
	
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	memset(cache, -1, sizeof(cache));
	int ret = solve(0,0);
	for (int i = 1; i < n; ++i) {
		ret = max(ret, solve(i, 0));
	}
	cout << ret << "\n";
}