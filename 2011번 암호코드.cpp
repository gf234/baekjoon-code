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

// 한 자리마다 탐색하기 위해 숫자를 스트링으로 받는다
string s;
int len = 0;
int DIV = 1000000;

// solve(pos): pos자리에서 만들 수 있는 암호의 개수
int cache[5001];
int solve(int pos) {
    if (pos > len) return 0;
    if (pos == len) return 1;
    // 처음 문자가 0이면 해석 불가능
    if (s[pos] == '0') return 0;

    int& ret = cache[pos];
    if (ret != -1) return ret;

    ret = 0;

    if (s[pos + 1] == '0') {
        // 다음글자가 0인경우 10 또는 20만 가능하다.
        if (s[pos] == '1' || s[pos] == '2')
            ret += solve(pos + 2) % DIV;
        else
            ret = 0;
    } else if (s[pos] == '1' ||
               (s[pos] == '2' && (s[pos + 1] <= '6' && s[pos + 1] != NULL))) {
        // 이번 글자가 1이나 2인경우(<=26) 2가지 경우가 가능하다
        ret += solve(pos + 1) % DIV + solve(pos + 2) % DIV;
    } else {
        ret += solve(pos + 1) % DIV;
    }
    return ret % DIV;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> s;

    len = s.length();

    cout << solve(0);
}
