# Intuition
I was thinking for a considerable time about more efficient solutions than the obvious, but only 2 came to mind, the first is just changing the original string whenever we encounter a dot and the second is the solution I'm submitting. In that one we create a new string where we can simply build up the answer. 

# Approach
1. Initialize an empty string **res** to store the defanged IP address.
2. Iterate over each character in the given **address** string.
3. If the current character is a period ('.'), append "[.]" to **res**.
4. Otherwise, append the current character to **res**.
5. Return the final **res** string, which represents the defanged IP address.

# Complexity
- Time complexity:
$O(n)$, where n is the length of the input **address**

- Space complexity:
$O(n)$, where n is the length of the input **address**

# Code
```c++
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                res += "[.]";
            }else {
                res += address[i];
            }
        }
        return res;
    }
};
```