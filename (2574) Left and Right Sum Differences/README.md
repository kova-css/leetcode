# Intuition
My first thought was to construct the final vector like it was constructed visually in the examples of the problem, 2 vectors from left and from right and then compared with abs.

# Approach
1. Create two arrays, **left** and **right**, of the same size as the input **nums** array to store the cumulative sums from the left and right sides, respectively.
2. Iterate from left to right over the **nums** array and calculate the cumulative sum up to each index. Store these sums in the **left** array.
3. Iterate from right to left over the **nums** array and calculate the cumulative sum from each index to the right end. Store these sums in the **right** array.
4. Iterate over the **sizes** (or **nums**) array again and calculate the absolute difference between the corresponding **left** and **right** elements at each index. Update the **left** array with these differences.
5. Return the modified **left** array, which now contains the absolute differences between the left and right sums for each element in the **nums** array.

# Complexity
- Time complexity:
$O(n)$, where n is the size of the input **nums** array

- Space complexity:
$O(n)$, where n is the size of the input **nums** array

# Code
```c++
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sizes = nums.size();
        vector<int> left(sizes), right(sizes);
        for (int i = 1; i < sizes; i++) {
            left[i] = left[i-1] + nums[i-1];
        }
        for (int i = sizes-2; i >= 0; i--) {
            right[i] = right[i+1] + nums[i+1];
        }
        for (int i = 0; i < sizes; i++) {
            left[i] = abs(left[i] - right[i]);
        }
        return left;
    }
};
```