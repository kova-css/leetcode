# Intuition
My first thought was to create a map where we can store each number's occourence, which then we can walk through to find out if there are any duplicates.

# Approach
1. Create an unordered map named **contains** to store the count of occurrences of each element in the **nums** vector.
2. Iterate over each element **itr** in the **nums** vector.
3. Increment the count of **itr** in the **contains** map.
4. Iterate over each element **itr** in the **contains** map.
5. If the count of **itr** is greater than 1, it means there is a duplicate element in the **nums** vector, so return **true**.
6. If no duplicates are found after the loop, return **false**.

The code uses an unordered map to efficiently keep track of the counts of each element. By checking the counts, it determines whether any element occurs more than once, indicating the presence of duplicates.

# Complexity
- Time complexity:
$$O(n)$$, where n is the number of elements in the **nums**

- Space complexity:
$$O(n)$$, where n is the number of elements in the **nums**

# Code
```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> contains;
        for (auto itr : nums) {
            contains[itr]++;
        }

        for (auto itr : contains) {
            if (itr.second > 1) {
                return true;
            }
        }
        return false;
    }
};
```