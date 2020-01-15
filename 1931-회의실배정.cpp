#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

// ȸ�� �ð� ����ü
struct time {
	int start;
	int end;

	time(int a, int b) {
		start = a;
		end = b;
	}
};

// ���� ������ ������ ����, ���� ��� ������ �� ����������
bool compare(time a, time b) {
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int n;
vector<time> times;

// ���� ���� ������ ȸ�Ǹ� ����
int solve() {
	int cnt = 0;

	int prevEnd = 0;
	for (int i = 0; i < times.size(); i++) {
		if (prevEnd <= times[i].start) {
			cnt++;
			prevEnd = times[i].end;
		}
	}
	return cnt;
}

int main() {
	// ȸ���� ��
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		times.push_back(time(a, b));
	}
	sort(times.begin(), times.end(), compare);


	cout << solve();
}