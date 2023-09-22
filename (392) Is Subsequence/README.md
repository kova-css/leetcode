# Intuition
My thought was to use a two pointer solution, where one individually goes through the first string, while the other tries to match the characters to the second. 

# Approach
1. Initialize a variable **scanner** to -1. This variable will keep track of the last character in string **t** that matches a character in string **s**.
2. Iterate through each character in string **s** using the outer loop. This loop is used to traverse each character in the subsequence **s**.
3. For each character in **s**, start an inner loop that iterates through the characters in string **t** from the position after the last matched character (i.e., **scanner + 1**) until the end of string **t**.
4. In the inner loop, check if the current character in **s** matches the current character in **t**. If there is a match, set the **found** flag to **true**, update the **scanner** to the current position in **t**, and break out of the inner loop.
5. If no match is found for the current character in **s** within the remaining portion of string **t**, return **false** because the subsequence cannot be found.
6. Continue this process for each character in **s**. If all characters in **s** are found in **t** in the same order, return **true**, indicating that **s** is a subsequence of **t**.

# Complexity
- Time complexity:
$O(m*n)$, where m is the length of **s** and n is the length of **t**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int scanner = -1;
        for (int i = 0; i < s.length(); i++) {
            bool found = false;
            for (int j = scanner+1; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    found = true;
                    scanner = j;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};
```