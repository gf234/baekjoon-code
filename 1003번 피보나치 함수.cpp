#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 0과 1이 나오는 횟수 세는 구조체
struct zeroAndOne {
	int zero;
	int one;

	zeroAndOne() {}
	zeroAndOne(int a, int b) {
		zero = a;
		one = b;
	}
	zeroAndOne operator+(zeroAndOne a) {
		zero += a.zero;
		one += a.one;
		return zeroAndOne(zero, one);
	}
	bool operator!=(const zeroAndOne &a) const{
		bool ret = true;
		if (zero != a.zero)
			ret = false;
		else if (one != a.one)
			ret = false;
		return !ret;
	}
};

int num;

// dp 이용
// solve(num) : num일때 0과 1이 출력되는 횟수
zeroAndOne cache[41];
zeroAndOne solve(int num) {
	if (num == 0)
		return zeroAndOne(1, 0);
	else if (num == 1)
		return zeroAndOne(0, 1);
	zeroAndOne& ret = cache[num];
	if (ret != zeroAndOne(-1,-1)) {
		return ret;
	}
	ret = solve(num - 1) + solve(num - 2);
	return ret;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int testNum = 1; testNum <= testCase; ++testNum) {
		cin >> num;

		// 캐쉬 초기화
		for (int i = 0; i < 41; ++i) {
			cache[i] = zeroAndOne(-1, -1);
		}

		zeroAndOne result = solve(num);
		cout << result.zero << " " << result.one << "\n";
	}
}