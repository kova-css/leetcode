#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
    int y = 0;
    while (x != 0) {
        if (y > INT32_MAX / 10 || y < INT32_MIN / 10) {
            return 0;
        }
        y = y * 10 + (x % 10);
        x /= 10;
    }
    return y;
}


int main() {
    cout << reverse(9646324351) << endl;


    return 0;
}