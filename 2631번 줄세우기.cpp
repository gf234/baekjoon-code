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
int nums[201];

// 마지막 숫자가 last이고 위치가 i일때 lis를 반환한다.
int cache[201][201];
int solve(int last, int i) {
    if (last == n) return 0;
    if (i == n) return 0;

    int& ret = cache[last][i];
    if (ret != -1) return ret;

    ret = solve(last, i + 1);
    if (last < nums[i])
        ret = max(ret, solve(nums[i], i + 1) + 1);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int lis = solve(0, 0);
    // lis를 제외한 나머지만 옮기면 된다.
    cout << n - lis;
}
