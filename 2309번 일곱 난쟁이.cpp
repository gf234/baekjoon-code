#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <climits>
#include <bitset>
using namespace std;

// height : 난쟁이들의 키
// all_pair : 빠질 2명들의 비트
// bit_set : 비트연산을 위한 변수
int height[9];
vector<bitset<9>> all_pair;
bitset<9> bit_set;

// 비트 마스크를 이용해서 9명중에 빠질 2명을 뽑는 모든 조합을 구한다.
void make_bin()
{
	int bit = 1;
	for (; bit != 0b110000001; ++bit)
	{
		bit_set = bit;
		if (bit_set.count() == 2)
			all_pair.push_back(bit_set);
	}
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		cin >> height[i];
	}

	make_bin();

	// pos : all_pair중 키의 합이 100이되는 위치
	int pos;
	for (pos = 0; pos < all_pair.size(); ++pos)
	{
		int sum = 0;
		for (int p = 0; p < 9; ++p)
		{
			// 비트가 1인 2명이 빠진다.
			if (all_pair[pos].test(p))
				continue;

			sum += height[p];
			if (sum > 100)
				break;
		}
		if (sum == 100)
			break;
	}
	// 오름차순으로 정렬하고 출력
	vector<int> result;
	for (int i = 0; i < 9; ++i)
	{
		if (all_pair[pos].test(i))
			continue;
		result.push_back(height[i]);
	}
	sort(result.begin(), result.end());

	for (int i = 0; i < 7; ++i)
	{
		cout << result[i] << '\n';
	}
}
