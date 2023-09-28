# Intuition
I decided to use the most obvious method, the two pointers. It is arguably the least efficient way to solve this, but it's 11PM and I want to sleep.

# Approach
1. Initialize a variable **scanner** to 0. This variable will keep track of the position where the next even number should be placed.
2. Iterate through the elements of the **nums** vector using a loop variable **i**.
3. For each element at index **i**, check if it's an even number (**nums[i] % 2 == 0**).
4. If the current element is even, perform the following steps:
    - Create a temporary variable **temp** and store the value of the even number (i.e., **temp = nums[i]**).
    - Shift elements to the right starting from the **scanner** position to make space for the even number. This is done by iterating from **i** down to **scanner** and moving each element one position to the right (**nums[j] = nums[j-1]**).
    - Place the even number **temp** at the **scanner** position in the **nums** vector.
    - Increment the **scanner** to the next position where an even number should be placed.
5. Continue this process for all elements in the **nums** vector.
6. Return the modified **nums** vector, which will now have all even numbers placed at the beginning in their original order, followed by the odd numbers.

# Complexity
- Time complexity:
$O(n^2)$, where n is the number of elements in the input vector **nums**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int scanner = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                int temp = nums[i];
                for (int j = i; j > scanner; j--) {
                    nums[j] = nums[j-1];
                }
                nums[scanner] = temp;
                scanner++;
            }
        }
        return nums;
    }
};
```