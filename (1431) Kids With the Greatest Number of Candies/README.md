# Intuition
After getting the max element, we can just compare the elements to the original vector with the plus candies.

# Approach
1. Find the maximum number of candies among all the kids. This can be done by using the **max_element** function from the **<algorithm>** library.
2. Initialize a vector **result** of the same size as the **candies** vector to store the result.
3. Iterate through the **candies** vector and compare each kid's number of candies plus the extra candies with the maximum number of candies.
    - If it is greater than or equal to the maximum, set the corresponding element in the **result** vector to **true**; otherwise, set it to **false**.
4. Return the **result** vector.

# Complexity
- Time complexity:
$O(n)$, where n is the number of elements in the **candies** vector

- Space complexity:
$O(n)$, where n is the number of elements in the **candies** vector

# Code
```c++
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            result[i] = candies[i] + extraCandies >= max ? true : false;
        }
        return result;
    }
};
```