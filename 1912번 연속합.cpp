#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int num[100000];

// maxSum[i] : i까지의 최대 부분합
// --> maxSum[i-1] + num[i] 아니면 num[i]가 된다.
int ret;
int maxSum[100000];
void calMaxSum() {
	maxSum[0] = num[0];
	ret = maxSum[0];
	for (int i = 1; i < n; ++i) {
		maxSum[i] = max(maxSum[i - 1] + num[i], num[i]);
		ret = max(ret, maxSum[i]);
	}
	return;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	calMaxSum();
	cout << ret << "\n";
}