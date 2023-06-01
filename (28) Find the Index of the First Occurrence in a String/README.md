# Intuition
Thanks to [@VEDBRO](https://leetcode.com/VEDBRO/) for spotting a problem in the solution!

I first thought about running through the string until we find a character that the needle starts with. Then we compare character-by-character the upcoming chars to the chars of the needle, on a successful hit, we return the position.

# Approach
1. Iterate over the **haystack** string from left to right using the variable **i** as the starting index.
2. For each character in **haystack** at index **i**, check if it matches the first character of **needle** (i.e., **haystack[i] == needle[0])**.
3. If there is a match, set the boolean variable **matches** to **true** and enter a nested loop using the variable **j** to compare the remaining characters of **needle** with the corresponding characters in **haystack**.
4. In the nested loop, compare **haystack[i + j]** with **needle[j]** for each **j** from 1 to the length of **needle**.
5. If any character in **needle** does not match the corresponding character in **haystack**, set matches to **false** and break out of the nested loop.
6. After the nested loop, check the value of **matches**. If it is **true**, it means that the entire **needle** string has been matched in **haystack** starting from index **i**. In this case, return the value of **i** as the index of the first occurrence.
7. If the loop completes without finding a match, or if **matches** is **false** after the nested loop, continue the outer loop to check the next character in **haystack**.
8. If the outer loop completes without finding any matches, return -1 to indicate that **needle** is not found in **haystack**.

This approach iterates over the **haystack** string and compares consecutive substrings of length equal to the length of **needle** with **needle** itself. It checks for matches and returns the index of the first occurrence or -1 if no occurrence is found.

# Complexity
- Time complexity:
$$O((n-m+1) * m)$$, where n is the length of the **haystack** string and m is the length of the **needle** string

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                bool matches = true;
                for (int j = 1; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        matches = false;
                        break;
                    }
                }
                if (matches) {
                    return i;
                }
            }
        }
        return -1;
    }
};
```