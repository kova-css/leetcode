# Intuition
I have no clue what is the most optimal solution to this problem, this should be one of them?

# Approach
1. Initialize a counter variable **ans** to keep track of the number of good pairs.
2. Create an array **t** of size 101 to store the count of each number in **nums**. Initialize all elements to 0.
3. Iterate through each element **num** in **nums**.
    - Increment the count of **num** in the array **t**.
4. Iterate through each element in the array **t**.
    - For each count **count** in **t**, calculate the number of good pairs that can be formed using the formula **count * (count - 1) / 2**.
    - Add the calculated value to **ans**.
5. Return the value of **ans** as the total number of good pairs in **nums**.

# Complexity
- Time complexity:
$O(n)$, where n is the size of the **nums** vector

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int t[101] = {0};
        for (int i = 0; i < nums.size(); i++) {
            t[nums[i]]++;
        }
        for (int i = 0; i < 101; i++) {
            ans += t[i] * (t[i] - 1) / 2;
        }
        return ans;
    }
};
```