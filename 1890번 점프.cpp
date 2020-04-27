#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n;
int map[100][100];

// 2^63-1 보다 작거나 같다고 했으니 unsigned long long을 쓴다.
// solve(i, j) : i,j에서 출발해서 마지막에 도달할 수 있는 경로의 개수
unsigned long long cache[101][101];
unsigned long long solve(int i, int j){
	if(i > n || j > n)
		return 0;
	if(i == n-1 && j == n-1)
		return 1;

	unsigned long long& ret = cache[i][j];
	if(ret != -1)
		return ret;
	ret = 0;

	ret += solve(i+map[i][j], j);
	ret += solve(i, j+map[i][j]);

	return ret;
}

int main() {
	cin >> n;
	for(int i =0; i<n;++i){
		for(int j = 0; j<n;++j){
			cin >> map[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));

	unsigned long long result = solve(0,0);
	cout << result;
}
