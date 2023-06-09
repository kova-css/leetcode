# Intuition
I first thought about searching for the smallest number and then comparing it with the values to the right, but apart from not really working it wouldn't even have been very efficient, so after working it out on paper I found a solution to iterate through the prices once, while comparing the minPrice or the maxProfit depending on changes in the minimum price. 

# Approach
1. Initialize **minPrice** to **INT_MAX** (a large value) to track the minimum price seen so far.
2. Initialize **maxProfit** to 0 to store the maximum profit that can be obtained.
3. Iterate over the **prices** vector, representing the stock prices on different days.
4. For each price:
    - Check if the current price is lower than the **minPrice**. If it is, update **minPrice** to the current price, as it represents a potential buying opportunity.
    - If the current price minus **minPrice** is greater than the current **maxProfit**, update **maxProfit** to the difference, as it represents a better selling opportunity.
5. After the loop, **maxProfit** will contain the maximum profit that can be obtained by buying at the lowest price and selling at the highest price.

The key idea behind this approach is to find the lowest price to buy and the highest price to sell, maximizing the profit. By iterating through the prices and keeping track of the minimum price seen so far, we can identify the potential buying points. Then, by comparing the difference between the current price and the minimum price with the current maximum profit, we can update the maximum profit if a higher profit is achievable.

# Complexity
- Time complexity:
$$O(n)$$, where n is the number of prices in the input vector

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};
```
