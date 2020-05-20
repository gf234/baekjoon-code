#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int map[1001];

// pos일때 오른쪽 끝으로 가는데 필요한 최소한의 점프 개수를 반환한다.
int cache[1001];
int solve(int pos) {
    if (pos >= n) return 987654321;
    if (pos == n - 1) return 0;

    int& ret = cache[pos];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int i = 1; i <= map[pos]; ++i) {
        ret = min(ret, solve(pos + i) + 1);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &map[i]);
    }
    int result = solve(0);
    if (result == 987654321)
        cout << -1;
    else
        cout << result;
}
