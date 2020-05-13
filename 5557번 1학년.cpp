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
int nums[100];

long long cache[892][101];
long long solve(int sum, int pos) {
    if (sum < 0 || sum > 20) return 0;
    if (pos == n - 2) {
        if (sum == nums[pos + 1])
            return 1;
        else
            return 0;
    }
    long long& ret = cache[sum][pos];
    if (ret != -1) return ret;

    ret = 0;

    ret += solve(sum - nums[pos + 1], pos + 1) +
           solve(sum + nums[pos + 1], pos + 1);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << solve(nums[0], 0);
}
