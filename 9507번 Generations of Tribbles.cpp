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

long long cache[68];
long long koong(int n) {
    if (n < 2) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    long long& ret = cache[n];
    if (ret != -1) return ret;

    ret = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int t;
    cin >> t;
    for (int tN = 1; tN <= t; ++tN) {
        int n;
        cin >> n;

        cout << koong(n) << '\n';
    }
}
