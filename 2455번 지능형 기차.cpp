#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <climits>
using namespace std;

int main()
{
	int max_p = 0;
	int sum, dim, cur = 0;
	for (int i = 0; i < 4; ++i)
	{
		cin >> dim >> sum;
		cur += sum - dim;
		max_p = max(max_p, cur);
	}
	cout << max_p;
}
