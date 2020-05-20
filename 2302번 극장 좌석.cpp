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
int vip[41];

// n개를 배치하는 방법의 수를 반환한다.
long long cache[41];
long long solve(int n) {
    // 계산을 편하게 하기 위해 만든 조건
    if (n <= 0) return 1;
    if (n == 2) return 2;
    if (n == 1) return 1;

    long long& ret = cache[n];
    if (ret != -1) return ret;

    ret = solve(n - 1) + solve(n - 2);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    cin >> m;
    int start = 1;
    long long cnt = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> vip[i];
        cnt *= solve(vip[i] - start);
        start = vip[i] + 1;
    }
    cnt *= solve(n - start + 1);
    cout << cnt;
}
