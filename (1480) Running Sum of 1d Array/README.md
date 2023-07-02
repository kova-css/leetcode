# Intuition
We can solve the problem by simulating a snowball which is rolling down a snowy hill and becoming larger as it picks up snow on its way down.

# Approach
1. Initialize a variable **carry** to keep track of the running sum.
2. Iterate through the elements of the input vector **nums**.
3. For each element, add its value to the **carry** and update the element in the **nums** vector with the current value of **carry**.
4. After processing all elements, the **nums** vector will contain the running sum values.
5. Return the modified **nums** vector as the result.

# Complexity
- Time complexity:
$O(n)$, where n is the size of the input vector **nums**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int carry = 0;
        for (int i = 0; i < nums.size(); i++) {
            carry += nums[i];
            nums[i] = carry;
        }
        return nums;
    }
};
```