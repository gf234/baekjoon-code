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

int n, nbit;
int w[17][17];

// visit : 비트마스크를 이용한 방문한 도시의 정보
// pos : 현재 위치
int cache[1 << 17][17];
int solve(int visit, int pos) {
    if (visit == nbit) {
        if (!w[pos][0]) return 987654321;
        return w[pos][0];
    }
    int& ret = cache[visit][pos];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int i = 0; i < n; ++i) {
        if (!w[pos][i]) continue;
        if (visit & (1 << i)) continue;
        ret = min(ret, solve(visit | (1 << i), i) + w[pos][i]);
    }
    return ret;
}
int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }
    nbit = 1;
    for (int i = 0; i < n - 1; ++i) {
        nbit <<= 1;
        nbit++;
    }
    cout << solve(1, 0);
}
