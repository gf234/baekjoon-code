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

// digit : n의 자리수
int n, m, digit;
int broken[10];

// 현재 ch채널이고 cnt만큼 눌렀을때 n에 도달하는데 버튼을 최소 몇번 눌러야하는지 반환한다.
int solve(int ch, int cnt) {
    // n보다 1 큰 자리수까지 검사한다.
    if (cnt == digit + 2) return 987654321;
    int ret = abs(n - ch) + cnt;
    for (int i = 0; i < 10; ++i) {
        if (!broken[i])
            ret = min(ret, solve(ch * 10 + i, cnt + 1));
    }
    return ret;
}

int main() {
    cin >> n;
    cin >> m;
    digit = to_string(n).size();
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        broken[temp] = 1;
    }

    int result = abs(n - 100);
    if (m != 10) {
        for (int i = 0; i < 10; ++i) {
            if (!broken[i])
                result = min(result, solve(i, 1));
        }
    }
    cout << result;
}
