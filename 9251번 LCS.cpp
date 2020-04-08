#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;


string str1, str2;
int table[1001][1001];

int main() {
	int LCS_length = 0, max;

	cin >> str1 >> str2;
	// 계산을 편하게 하기 위해 맨 앞에 0을 붙여준다.
	str1 = '0' + str1;
	str2 = '0' + str2;

	int len1, len2;
	len1 = str1.length();
	len2 = str2.length();

	for (int i = 1; i < len2; i++) {
		max = 0;
		// 첫번째열은 모두 0
		table[i][0] = 0;
		for (int j = 1; j < len1; j++) {
			// 같은 경우 : 왼쪽 위 + 1
			if (str2[i] == str1[j]) {
				max = table[i - 1][j - 1] + 1;
				table[i][j] = max;
			}
			// 다른 경우 : 왼쪽과 위 중 큰것으로 선택
			else {
				if (table[i][j - 1] > table[i - 1][j])
					table[i][j] = table[i][j - 1];
				else
					table[i][j] = table[i - 1][j];
			}
		}
		if (LCS_length < max)
			LCS_length = max;
	}
	
	cout << LCS_length << '\n';

	return 0;
}