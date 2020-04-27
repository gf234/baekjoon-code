#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n;
bool rooms[101];

// k의 배수에 해당하는 값만 반전
void solve(int k){
	for(int i = 1; i<=n;++i){
		if(i % k == 0)
			rooms[i] = !rooms[i];
	}
}

int main() {
	int t;
	cin >> t;
	for(int testCase = 1; testCase <=t; ++testCase){
		cin >> n;
		memset(rooms,0,sizeof(rooms));

		for(int i = 1; i<=n;++i){
			solve(i);
		}	
		int cnt = 0;	
		for(int i = 1; i<=n;++i){
			if(rooms[i])
				cnt++;
		}
		cout << cnt << '\n';
	}
}
