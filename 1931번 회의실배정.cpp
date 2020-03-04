#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

// 회의 시간 구조체
struct time {
	int start;
	int end;

	time(int a, int b) {
		start = a;
		end = b;
	}
};

// 빨리 끝나는 순서로 정렬, 같은 경우 시작이 더 빠른순으로
bool compare(time a, time b) {
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int n;
vector<time> times;

// 제일 빨리 끝나는 회의를 선택
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
	// 회의의 수
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		times.push_back(time(a, b));
	}
	sort(times.begin(), times.end(), compare);


	cout << solve();
}