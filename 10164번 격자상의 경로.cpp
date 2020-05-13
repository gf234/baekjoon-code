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

int n, m, p;

// 이동하는것을 전체 크기가 줄어드는것으로 생각
// row, col크기의 행렬에서 오른쪽 끝으로 이동하는 경로의 수
int cache[16][16];
int solve(int row, int col) {
    if (row == 0 || col == 0) return 0;
    if (row == 1 && col == 1) return 1;

    int& ret = cache[row][col];
    if (ret != -1) return ret;

    ret = solve(row, col - 1) + solve(row - 1, col);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n >> m >> p;

    int result;
    if (p == 0) {
        result = solve(n, m);
    } else {
        // 함수에 크기를 넣어야 하기 때문에 p의 자리를 구한다.
        int temp_col = p % m;
        if (temp_col == 0) temp_col = m;
        int temp_row = (p - 1) / m + 1;
        result = solve(temp_row, temp_col) * solve(n - temp_row + 1, m - temp_col + 1);
    }
    cout << result;
}
