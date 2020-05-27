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

int n, m;
int coins[20];

// 중복을 없애기 위해 coins의 index를 받아 index보다 같거나 큰 값만을 이용
// 현재 sum일때 m을 만드는 방법의 개수
int cache[10001][20];
int solve(int sum, int index) {
    if (sum > m) return 0;
    if (sum == m) return 1;

    int& ret = cache[sum][index];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = index; i < n; ++i) {
        ret += solve(sum + coins[i], i);
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    for (int tn = 1; tn <= t; ++tn) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> coins[i];
        }
        cin >> m;

        cout << solve(0, 0) << '\n';
    }
}
