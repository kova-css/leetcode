#include <bits/stdc++.h>

using namespace std;


int romanToInt(string s) {
    unordered_map<char, int> roman_values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        if (roman_values[s[i]] < roman_values[s[i + 1]]) {
            result -= roman_values[s[i]];
        } else {
            result += roman_values[s[i]];
        }
    }

    result += roman_values[s.back()];

    return result;
}



int main() {
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}