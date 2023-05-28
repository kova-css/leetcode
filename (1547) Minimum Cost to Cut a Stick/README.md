# Intuition
Ok, this was hard, but the hints really helped out. After a lot of trying out random approached I found one solution was to consider all possible cuts and the associated costs with which we build a matrix that represents the minimum cost to cut the stick between two positions. We can just simply then return the [0][n] element as the answer.

# Approach
1. Sort the cuts array in ascending order to ensure the positions are in increasing order.
2. Create a **newCuts** array to include the starting point (0), the positions of the cuts, and the ending point (n).
3. Initialize a 2D dynamic programming table, **dp**, with dimensions (**m x m**), where **m** is the size of the **newCuts** array.
4. Iterate over the possible lengths of subsegments (**len**) in the range **[2, m)**, starting from the smallest subsegments and gradually increasing the length.
5. For each length, iterate over all possible starting positions (**i**) within the **newCuts** array, considering each subsegment.
6. Compute the ending position (**j**) based on the starting position (**i**) and the length (**len**).
7. Initialize the cost of cutting the subsegment between **i** and **j** as infinity (INT_MAX).
8. Iterate over all possible partition positions (**k**) within the subsegment, except for the endpoints.
9. Update the minimum cost (**dp[i][j]**) by considering the cost of cutting the subsegment at position **k** and recursively calculating the costs of the left and right subsegments.
10. The cost of cutting the subsegment between **i** and **j** is the sum of the costs of the left and right subsegments plus the cost of cutting the subsegment itself (**newCuts[j] - newCuts[i]**).
11. Store the minimum cost (**dp[0][m - 1]**), which represents the minimum cost to cut the entire stick.
12. Return the minimum cost as the result.

# Complexity
- Time complexity:
$$O(n^3 + n log n)$$
    - Beats:
    **58.37%**

- Space complexity:
$$O(n^2)$$
    - Beats:
    **32.53%**
# Code
```c++
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        vector<int> newCuts;
        newCuts.push_back(0);
        newCuts.insert(newCuts.end(), cuts.begin(), cuts.end());
        newCuts.push_back(n);

        int m = newCuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int i = 0; i < m - len; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + newCuts[j] - newCuts[i]);
                }
            }
        }

        return dp[0][m - 1];

    }
};
```