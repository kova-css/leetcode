# Intuition
The intuition behind the backtracking approach for generating permutations is to systematically explore all possible arrangements of the given numbers. By building the permutations incrementally, we can ensure that each number is used exactly once in each permutation.

# Approach
The approach used in the code is backtracking to generate all permutations of the given numbers. The main idea is to build permutations incrementally by selecting one number at a time and backtracking when all numbers have been used.

The backtracking algorithm works as follows:
1. If the current permutation is of the same length as the input array, add it to the result.
2. Iterate through each number in the input array.
3. If the number has already been used in the current permutation, skip it.
4. Add the number to the current permutation and mark it as used.
5. Recursively call the backtrack function to generate permutations with the updated permutation and used array.
6. After the recursive call, remove the last added number from the permutation and mark it as unused.
7. Repeat steps 3-6 for the remaining unused numbers.
8. Return the resulting list of permutations.

This approach guarantees that all possible permutations of the given numbers will be generated.

# Complexity
- Time complexity:
$$O(N!)$$, where N is the number of elements in the input array **nums**
It's important to note that the time complexity can be expressed as $$O(N*N!)$$ because generating each permutation takes $$O(N)$$ time, and there are **N!** permutations in total.

- Space complexity:
$$O(N)$$, where N is the number of elements in the input array **nums**

# Code
```c++
class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutation, vector<bool>& used) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            permutation.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, result, permutation, used);

            permutation.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);

        backtrack(nums, result, permutation, used);

        return result;
    }
};
```