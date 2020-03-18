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

// cache[i] : i�� ���� �� �ִ� ����� ��
int cache[10001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) 
		cin >> coinValue[i];
	
	// ����� �� �ִ� ������ ������ �����ϸ鼭 ������Ʈ
	cache[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = coinValue[i]; j <= k; ++j) {
			// cache[j] : i��° ������ ���� �ʾ����� + i��° ������ �Ѱ� ���ٰ� �����ϰ� �������� ����� �� ( ������� ���ϱ� ������ i��° ������ ������ ���� ��쵵 ���Եȴ�. )
			cache[j] = cache[j] + cache[j - coinValue[i]];
		}
	}
	cout << cache[k] << '\n';
	return 0;
}