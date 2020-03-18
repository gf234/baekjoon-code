#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#include <limits>
using namespace std;

int n, k;
int coinValue[100];

// cache[i] : i를 만들 수 있는 경우의 수
int cache[10001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) 
		cin >> coinValue[i];
	
	// 사용할 수 있는 동전의 개수를 제한하면서 업데이트
	cache[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = coinValue[i]; j <= k; ++j) {
			// cache[j] : i번째 동전을 쓰지 않았을때 + i번째 동전을 한개 쓴다고 생각하고 나머지의 경우의 수 ( 순서대로 구하기 때문에 i번째 동전을 여러개 쓰는 경우도 포함된다. )
			cache[j] = cache[j] + cache[j - coinValue[i]];
		}
	}
	cout << cache[k] << '\n';
	return 0;
}