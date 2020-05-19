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

int n, s, m;
int v[101];

// 현재 volume이고 pos번째 곡일때 마지막 곡의 최대값 반환
int cache[1001][101];
int solve(int volume, int pos) {
    if (volume > m || volume < 0) return -1;
    if (pos == n) return volume;

    int& ret = cache[volume][pos];
    // cache의 초기값을 절대로 저장하지 않는 값으로 !!!
    if (ret != 0) return ret;

    ret = max(solve(volume + v[pos], pos + 1), solve(volume - v[pos], pos + 1));
    return ret;
}

int main() {
    cin >> n >> s >> m;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(s, 0);
}
