# Intuition
I spent a good 10 minutes writing a beautiful solution, but realized at the end that the non-strict monotomy is also accepted, so I needed to rewrite it all. I ended up splitting the array into 3 possible cases, from where I could check with only a single pointer. 

# Approach
1. heck the difference between the last element (**nums[nums.size() - 1]**) and the first element (**nums[0]**) of the **nums** vector.
    - If the difference is 0, it means all elements in the vector are the same. In this case, the vector is considered monotonic, so proceed to step 2.
    - If the difference is greater than 0, it indicates that the vector is non-decreasing (monotonic increasing). Proceed to step 3.
    - If the difference is less than 0, it indicates that the vector is non-increasing (monotonic decreasing). Proceed to step 4.
2. If the difference is 0 (all elements are the same), iterate through the vector using a loop variable **i** and check if each element is equal to the previous element. If any pair of adjacent elements is not equal, return **false**. Otherwise, return **true** at the end of the loop.
3. If the difference is greater than 0 (monotonic increasing), iterate through the vector using a loop variable **i** and check if each element is less than or equal to the previous element. If any element is greater than the previous one, return **false**. Otherwise, return **true** at the end of the loop.
4. If the difference is less than 0 (monotonic decreasing), iterate through the vector using a loop variable **i** and check if each element is greater than or equal to the previous element. If any element is less than the previous one, return **false**. Otherwise, return **true** at the end of the loop.
# Complexity
- Time complexity:
$O(n)$, where n is the number of elements in the **nums**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
   bool isMonotonic(vector<int>& nums) {
        if (nums[nums.size() - 1] - nums[0] == 0) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] != nums[i - 1]) {
                    return false;
                }
            }
        }else if (nums[nums.size() - 1] - nums[0] > 0) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    return false;
                }
            }
        }else {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > nums[i - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```