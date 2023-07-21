# Intuition
We need to count the opening and closing parentheses' sequence.

# Approach
1. Initialize two variables, **maxDepth** and **curDepth**, both set to 0. These variables will keep track of the maximum nesting depth and the current nesting depth, respectively.
2. Iterate over each character in the input string **s**.
3. If the current character is '(', increment the **curDepth** to represent nesting inside a pair of parentheses. Also, update the **maxDepth** if **curDepth** is greater than the current **maxDepth**.
4. If the current character is ')', decrement the **curDepth** to represent the end of nesting inside a pair of parentheses.
5. Return the **maxDepth** as the maximum nesting depth of the parentheses in the given string.

# Complexity
- Time complexity:
$O(n)$, where n is the length of the input string **s**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0, curDepth = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                curDepth++;
                if (curDepth > maxDepth) {
                    maxDepth = curDepth;
                }
            }else if (s[i] == ')') {
                curDepth--;
            }
        }
        return maxDepth;
    }
};
```