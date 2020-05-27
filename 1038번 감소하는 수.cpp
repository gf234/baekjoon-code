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

int main() {
    int n;
    cin >> n;

    // 9876543210이 1022번째 수 이다.
    if (n > 1022) {
        cout << -1;
        return 0;
    }
    // num : 증가시키면서 확인할 숫자
    // result : 최종 결과
    unsigned long long num = 0;
    unsigned long long result = 0;
    // 0~n번째까지 반복
    for (int i = 0; i <= n; ++i) {
        // i번째 num을 구할때까지 반복
        while (true) {
            // inc_pos : 증가시킬 위치
            unsigned long long inc_pos = 1;
            // is_dec : 감소하는수인지 확인하는 변수
            bool is_dec = true;
            // 1의자리수는 바로 반환한다.
            if (num / 10 < 1) break;
            // pos : num의 자리수
            unsigned long long pos = 1;
            // num을 1의 자리수부터 차례대로 비교한다.
            for (unsigned long long i = num; i >= 10; i /= 10, pos *= 10) {
                // 감소하지않는 제일 큰 자리수를 저장한다.
                if (i % 10 >= (i / 10) % 10) {
                    is_dec = false;
                    inc_pos = pos * 10;
                }
            }
            if (is_dec) break;
            // 증가시키고 그 밑의 자리수들은 0으로 만들어준다.
            num = num + inc_pos - (num % inc_pos);
        }
        result = num++;
    }
    cout << result;
    return 0;
}
