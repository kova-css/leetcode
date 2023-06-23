# Intuition
Initially, I thought of solving the problem by trying all possible arithmetic subsequences, but that approach seemed inefficient. Instead, I had an idea to use dynamic programming. By keeping track of the longest arithmetic subsequence ending at each element, I could find the overall longest arithmetic subsequence more efficiently. This insight made me realize that I could iterate through the elements, comparing their differences with the previous elements and updating the dynamic programming table accordingly.

# Approach
1. Initialize a nested unordered map **dp** to store the length of the arithmetic subsequence for each element and difference encountered so far. The key of the outer map represents the index of the element, and the key of the inner map represents the difference.
2. Iterate over the elements of the input **nums** from left to right.
3. For each element **nums[i]**, iterate over the elements before it (from 0 to i-1).
4. Calculate the difference between **nums[i]** and each previous element **nums[j]**.
5. If the difference is already present in **dp[j]**, it means we have an arithmetic subsequence with that difference ending at **nums[j]**. So, we update **dp[i][diff]** by adding 1 to the length of that subsequence. Also, update the **maxLen** variable if necessary.
6. If the difference is not present in **dp[j]**, it means we have a new arithmetic subsequence with that difference starting at **nums[j]**. So, we initialize **dp[i][diff]** with a length of 2.
7. Repeat steps 3-6 for all elements.
8. Finally, return the **maxLen**, which represents the length of the longest arithmetic subsequence found.

The dynamic programming approach efficiently stores and updates the lengths of arithmetic subsequences for different differences, allowing us to find the maximum length.

# Complexity
- Time complexity:
$O(n^2)$, where n is the size of the input **nums** vector

- Space complexity:
$O(n^2)$, where n is the size of the input **nums** vector

*It's worth noting that if the input array **nums** has a small size or is bounded by a constant, the space complexity can be considered $O(1)$ since the maximum size of **dp** is fixed.*

# Code
```c++
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2;

        unordered_map<int, unordered_map<int, int>> dp;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                if (dp[j].count(diff)) {
                    int prevLen = dp[j][diff];
                    dp[i][diff] = prevLen + 1;
                    maxLen = max(maxLen, dp[i][diff]);
                } else {
                    dp[i][diff] = 2;
                }
            }
        }

        return maxLen;
    }
};
```