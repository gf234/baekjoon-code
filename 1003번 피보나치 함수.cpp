#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 0�� 1�� ������ Ƚ�� ���� ����ü
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

// dp �̿�
// solve(num) : num�϶� 0�� 1�� ��µǴ� Ƚ��
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

		// ĳ�� �ʱ�ȭ
		for (int i = 0; i < 41; ++i) {
			cache[i] = zeroAndOne(-1, -1);
		}

		zeroAndOne result = solve(num);
		cout << result.zero << " " << result.one << "\n";
	}
}