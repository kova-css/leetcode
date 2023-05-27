# Intuition
This one was very simple, my first thought was to just walk through the array and when we found the value just remove it. Not the most efficient, but I think it's okay as it's still stupidly quick on big arrays. This can be improved with an approach I had taken in the 26th problem.

# Approach
1. Start iterating over the elements of **nums** using the index variable **i** from 0 to **nums.size()**.
2. Check if the current element **nums[i]** is equal to the target value **val**.
3. If **nums[i]** is equal to **val**, it indicates an element that needs to be removed.
4. Use the **erase** function to remove the element at index **i** from the **nums** vector.
5. Decrement **i** by 1 to account for the shifted indices after the removal.
6. Repeat steps 2-5 for the remaining elements in the vector.
7. After the loop, return the updated size of the vector **nums**.

This approach removes all occurrences of **val** from the vector by modifying it in-place.

# Complexity
- Time complexity:
$$O(n^2)$$, where n is the size of the input vector **nums**

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};
```