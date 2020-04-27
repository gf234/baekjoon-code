#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n;
int numbers[1000];

// pos : 이번에 고를 상자의 위치
// prev : 이전에 골랐던 상자의 크기
int cache[1001][1001];
int solve(int pos, int prev){
	if(pos == n)
		return 0;

	int& ret = cache[pos][prev];
	if(ret != -1)
		return ret;

	ret = solve(pos+1, prev);
	if(prev < numbers[pos])
		ret = max(ret, 1+solve(pos+1, numbers[pos]));

	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i<n;++i){
		cin >> numbers[i];
	}
	memset(cache,-1,sizeof(cache));
	
	int result = solve(0, 0);
	cout << result;
}
