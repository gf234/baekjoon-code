#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n;
int map[500][500];
int directionX[]= {1,-1,0,0};
int directionY[]= {0,0,1,-1};

// solve(i, j) : i, j 위치에서 판다가 살 수 있는 최대 일수
int cache[501][501];
int solve(int i, int j){
	if(i >= n || j >= n || i<0 || j <0)
		return 0;

	int& ret = cache[i][j];
	if(ret != -1)
		return ret;

	ret = 1;
	for(int k = 0; k < 4;++k){
		if(map[i][j] < map[i+directionX[k]][j+directionY[k]])
			ret = max(ret, 1 + solve(i+directionX[k], j+directionY[k]));
	}
	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i<n;++i){
		for(int j = 0; j<n;++j){
			cin >> map[i][j];
		}
	}
	memset(cache,-1,sizeof(cache));
	int result = 1;
	for(int i = 0; i<n;++i){
		for(int j = 0; j<n;++j){
			result = max(result, solve(i,j));
		}
	}
	
	cout << result;
}
