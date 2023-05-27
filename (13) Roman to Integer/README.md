# Intuition
By far the hardest part of this problem was to understand how Roman numerals work lmao. After some studying I had already had a concept in mind, using a map to compare values from left to right.

# Approach
1. Create an unordered map called **roman_values** to store the mapping of Roman numerals to their corresponding integer values. Each Roman numeral character ('I', 'V', 'X', etc.) is mapped to its respective integer value (1, 5, 10, etc.).
2.  Initialize the **result** variable to 0, which will hold the final integer value.
3. Iterate over the input string **s** from the first character to the second-to-last character. For each character at index **i**, compare its value with the value of the next character at index **i + 1**.
4. If the value of the Roman numeral at index **i** is less than the value of the Roman numeral at index **i + 1**, it indicates that a subtraction case is encountered (e.g., "IV" for 4 or "IX" for 9). In this case, subtract the value of the Roman numeral at index **i** from the **result**.
5. Otherwise, if the value of the Roman numeral at index **i** is greater than or equal to the value of the Roman numeral at index **i + 1**, it indicates a normal addition case. In this case, add the value of the Roman numeral at index **i** to the **result**.
6. After the loop, add the value of the last Roman numeral in the string **s** to the **result**.
7. Finally, return the **result** as the converted integer value.

# Complexity
- Time complexity:
$$O(n)$$, where n is the length of the input string **s**

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
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
};
```