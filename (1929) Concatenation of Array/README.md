# Intuition
This is a pretty straightforward problem, but I actually think this is one of the few problems where regular arrays may be more efficient than vectors (since we won't need to resize the array)? I don't know for 100% the inner workings of the push_back function and I haven't tested it, but I think it's a possibility.

# Approach
1. Create a variable **s** and initialize it with the size of the input array **nums**.
2. Iterate over the elements of **nums** using a for loop from index 0 to **s - 1**.
3. Inside the loop, append each element of **nums** to the end of the array using the **push_back()** function.
4. After the loop, return the modified **nums** array.

# Complexity
- Time complexity:
$O(n)$, where n is the size of the input array **nums**

- Space complexity:
$O(n)$, where n is the size of the input array **nums**

# Code
```c++
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int s = nums.size();
        for (int i = 0 ; i < s; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
```