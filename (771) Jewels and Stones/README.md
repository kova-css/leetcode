# Intuition
Hashmap should be faster but these tests are very small, so O(n*m) is preferred.

# Approach
1. Initialize a variable **ans** to keep track of the count of jewels found in stones.
2. Iterate through each character **j** in the string **jewels**.
    - For each character **j**, iterate through each character **s** in the string **stones**.
    - If **j** matches **s**, increment **ans** by 1.
3. Return the final value of **ans**.

# Complexity
- Time complexity:
$O(n*m)$, where n is the length of the **jewels** string and m is the length of the **stones** string

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (int i = 0; i < jewels.length(); i++) {
            for (int j = 0; j < stones.length(); j++) {
                if (jewels[i] == stones[j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```