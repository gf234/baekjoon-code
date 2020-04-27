#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n, k;
int DIV = 1000000000;

// solve(sum, choose) : choose개 골랐고 합이 sum일때 N을 만들 수 있는 경우의 수.
int cache[201][201];
int solve(int sum, int choose){
	if(sum > n || choose > k)
		return 0;
	if(sum == n)
		return 1;

	int& ret = cache[sum][choose];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int i = 0; i<=n;++i){
		ret = (ret + solve(sum+i, choose+1)) % DIV;
	}
	return ret;
}

int main() {
	cin >> n >> k;

	memset(cache,-1,sizeof(cache));

	int result = solve(0,0);
	cout << result;
}
