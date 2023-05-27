#include <bits/stdc++.h>

using namespace std;

int reverse(long long x) {
    long long y = 0;
    bool minus = false;
    if (x < 0) {
        minus = true;
        x = -x;
    }
    while (x > 0) {
        y = y * 10 + (x % 10);
        x/=10;
    }
    if (y < INT32_MIN || y > INT32_MAX) {
        return 0;
    }
    return minus ? -y : y;
}


int main() {
    cout << reverse(9646324351) << endl;


    return 0;
}