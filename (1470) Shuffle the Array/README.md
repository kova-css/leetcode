# Intuition
I was actually struggling a bit because I wanted to solve it using a single loop and I was always miscalculating steps, but got it eventually

# Approach
1. Create a new vector called **shuffle** with a size of 2 times the value of **n**.
Use a loop to iterate from 0 to **n+2** with a step of 2.
2. Inside the loop, assign the value of **nums[i/2]** to **shuffle[i]** and the value of **nums[i/2+n]** to **shuffle[i+1]**.
3. Here, **i/2** represents the index in the original array **nums** before the middle index **n**, and **i/2+n** represents the index after the middle index.
4. Return the **shuffle** vector.

# Complexity
- Time complexity:
$O(n)$, where n represents the size of the input vector **nums**

- Space complexity:
$O(n)$, where n represents the size of the input vector **nums**

# Code
```c++
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffle(n*2);
        for (int i = 0; i < n*2; i+=2) {
            shuffle[i] = nums[i/2];
            shuffle[i+1] = nums[i/2+n];
        }
        return shuffle;
    }
};
```