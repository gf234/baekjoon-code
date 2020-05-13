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

int nums[2001];

// solve(a,b) : a~b가 팰린드롬인지 판별
int cache[2001][2001];
int solve(int a, int b) {
    if (a >= b) return 1;

    int& ret = cache[a][b];
    if (ret != -1) return ret;

    if (nums[a] == nums[b]) {
        ret = solve(a + 1, b - 1);
        return ret;
    } else {
        ret = 0;
        return ret;
    }
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }
    getchar();
    int m;
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        getchar();
        printf("%d\n", solve(a, b));
    }
}
