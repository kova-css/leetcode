#include <bits/stdc++.h>

using namespace std;

    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0) {
            return false;
        }
        int size = log10(x)+1;
        for (int i = 0; i < size/2; i++) {
            int lastDigit = (x % ((int) (pow(10, (i+1))))) / pow(10, i);
            int firstDigit = ((int) (x / (pow(10,size-1) / pow(10, i)))) % 10;
            if (firstDigit != lastDigit) {
                return false;
            }                        
        }
        return true;
    }

int main() {
    cout << isPalindrome(12345) << endl;
    return 0;
}