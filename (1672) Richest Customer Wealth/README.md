# Intuition
We can just loop through the accounts and evaluate the max pocket sequentially.

# Approach
1. Initialize a variable **max** to store the maximum wealth found so far and set it to the minimum possible value.
2. Get the number of customers (accounts) **accountsNum** by accessing the size of the **accounts** vector.
3. Get the size of each customer's wealth (number of pockets) **pocketsize** by accessing the size of the first element in **accounts**.
4. Iterate over each customer's wealth using nested loops:
    - Outer loop iterates over **accountsNum** to access each customer.
    - Inner loop iterates over **pocketsize** to access each pocket of a customer.
5. Calculate the total wealth of the current customer by summing up the values in their pockets and store it in a temporary variable **temp**.
6. Check if **temp** is greater than the current maximum wealth **max**. If so, update **max** with the new maximum value.
7. After iterating over all customers, return the maximum wealth value stored in **max**.

# Complexity
- Time complexity:
$O(n * m)$, where n is the number of customers (**accounts**) and m is the size of each customer's wealth (**number of pockets**)

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = INT_MIN;
        int pocketsize = accounts[0].size();
        int accountsNum = accounts.size();
        for (int i = 0; i < accountsNum; i++) {
            int temp = 0;
            for (int j = 0; j < pocketsize; j++) {
                temp += accounts[i][j];
            }
            if (temp > max){
                max = temp;
            }
        }
        return max;
    }
};
```