# Intuition
You only need the middle character of the strings to solve the problem

# Approach
1. Initialize the answer variable **ans**.
2. Iterate throught **operations** and add or substract based on the middle character of the string.
3. Return **ans**.

# Complexity
- Time complexity:
$O(n)$, where n is the size of the **operations** vector

- Space complexity:
$O(n)$, where n is the size of the **operations** vector

# Code
```c++
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int fin = 0;
        for (int i = 0; i < operations.size(); i++) {
            fin += operations[i][1] == '+' ? 1 : -1;
        }
        return fin;
    }
};
```