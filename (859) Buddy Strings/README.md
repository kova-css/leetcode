# Intuition
We can solve the problem without swapping a single element by searching for invalidating characteristics.

# Approach
1. Create two unordered maps, **map1** and **map2**, to store the frequency of characters in strings **s** and **goal**, respectively.
2. Initialize a variable **diffs** to keep track of the number of differing characters between **s** and **goal**.
3. Check if the lengths of **s** and **goal** are equal. If not, return **false** as they cannot be buddy strings.
4. Iterate over each character in **s** and **goal** simultaneously:
    - Increment the frequency of the current character in **map1** and **map2**.
    - If the characters at the current index in **s** and **goal** are different, increment **diffs**.
5. Check the following conditions:
    - If **map1** is not equal to **map2**, the characters and their frequencies do not match, return **false**.
    - If **diffs** is greater than 2, there are more than two differing characters, return **false**.
    - If **s** is equal to **goal** and there are no characters with even frequency in **map1**, return **false**.
6. If none of the above conditions are met, return **true** as **s** and **goal** are buddy strings.

# Complexity
- Time complexity:
$O(n)$, where n is the length of the input strings **s** and **goal**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    bool existsEven(unordered_map<char, int> map) {
        for (int i = 'a'; i < 'z'; i++) {
            if (map[i] >= 2) {
                return true;
            }
        }
        return false;
    }

    bool buddyStrings(string s, string goal) {
        unordered_map<char, int> map1, map2;
        int diffs = 0;

        if (s.length() != goal.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            map1[s[i]]++;
            map2[goal[i]]++;
            if (s[i] != goal[i]) {
                diffs++;
            }
        }

        if (map1 != map2 || diffs > 2 || (s == goal && !existsEven(map1))) {
            return false;
        }
        
        return true;
    }
};
```