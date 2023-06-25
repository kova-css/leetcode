# Intuition
Theres is the easy way where you just create a new vector, but I wanted a challenge , so I started to think about the possible $O(1)$ space complexity solution. I noticed that the values in **nums** were indices themselves. I thought, what if I could somehow encode the original values at those indices within the same array? That way, I wouldn't need any extra space for the result. I decided to try encoding the values by adding a multiple of the array size to each element. Then, I iterated over the array again, decoded the values, and returned the modified array. This approach achieves the $O(1)$ space complexity.

# Approach
1. Iterate through the given array **nums**.
2. For each element **nums[i]**, modify it by adding **s * (nums[nums[i]] % s)**. The expression **nums[nums[i]] % s** retrieves the original value at index **nums[i]** before modification. By adding **s * (nums[nums[i]] % s)**, we store the modified value at index **i**.
3. After modifying all elements in the array, iterate through it again.
4. For each element **nums[i]**, divide it by **s** to retrieve the original value. Since the modified value was stored as **s * (nums[nums[i]] % s)**, dividing by **s** yields the original value at index **i**.
5. Return the modified **nums** array.

# Complexity
- Time complexity:
$O(n)$, where n is the size of the input array **nums**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int s = nums.size();

        for (int i = 0; i < s; i++) {
            nums[i] += s * (nums[nums[i]] % s);
        }

        for (int i = 0; i < s; i++) {
            nums[i] /= s;
        }

        return nums;
    }
};
```