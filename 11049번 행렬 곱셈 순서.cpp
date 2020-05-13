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
vector<pair<int, int>> matrix;

int cache[501][501];
int solve(int left, int right) {
    if (left == right) return 0;

    int& ret = cache[left][right];
    if (ret != -1) return ret;

    ret = INT_MAX;
    // 묶음은 2개로 나눠진다.
    // 나눠진것을 기준으로 어떤것이 곱해지는지 알 수 있다.
    for (int i = left; i < right; ++i) {
        ret = min(ret, solve(left, i) + solve(i + 1, right) +
                           matrix[left].first * matrix[i].second *
                               matrix[right].second);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        matrix.push_back(pair<int, int>(a, b));
    }
    getchar();
    cout << solve(0, n - 1);
}
