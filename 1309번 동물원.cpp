#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n;
int DIV = 9901;

// num : 몇번째 층인지
// state : 이전 상태가 무엇인지  0 : 00 , 1 : 01 , 2 : 10
int cache[100000][3];
int solve(int num, int state){
	if(num == n)
		return 1;
	int& ret = cache[num][state];
	if(ret != -1)
		return ret;
	num++;
	switch(state){
		case 0:
			ret = (solve(num, 0) + solve(num, 1) + solve(num, 2)) % DIV;
			break;
		case 1:
			ret = (solve(num, 0) + solve(num, 2)) % DIV;
			break;
		case 2:
			ret = (solve(num, 0) + solve(num, 1)) % DIV;
			break;
	}
	return ret;
}

int main() {
	cin >> n;

	memset(cache,-1,sizeof(cache));

	int result = solve(0,0);
	cout << result;
}
