# Intuition

I'd like to thank **[@maareftam](https://leetcode.com/maareftam/)** for spotting a critical problem in the solution<3. This is the fixed solution.

This one was fairly simple, we even did this in school. The main difference was that this problem required that the code to run in a 32-bit system. The main idea is that we have a new empty number and just one-by-one place the last digit of the original to the end of the new one, while being cautious about stepping over the limit.

# Approach
1. Initialize a variable **y** to store the reversed integer. Set it to 0 initially.
2. Iterate until the input integer **x** becomes 0.
3. Within each iteration:
  - Check if **y** is going to exceed the range of a 32-bit signed integer (**INT32_MAX** or **INT32_MIN**) after multiplying by 10. If so, return 0.
  -  Multiply **y** by 10 and add the least significant digit of **x** to **y** by calculating **x % 10**.
  - Update x by dividing it by 10 to remove the least significant digit.
4. After the iteration, return the final value of **y** as the reversed integer.

This approach reverses the given integer by iteratively extracting the least significant digit from **x** and appending it to the reversed integer **y**. The check for integer overflow is performed to ensure that the reversed integer remains within the range of a 32-bit signed integer.

# Complexity
- Time complexity:
$$O(log10(x))$$, where x is the input integer
    - Beats:
    **100%**

- Space complexity:
$$O(1)$$
    - Beats:
    **57.80%**

# Code
```c++
class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while (x != 0) {
            if (y > INT32_MAX / 10 || y < INT32_MIN / 10)
                return 0;
            y = y * 10 + (x % 10);
            x /= 10;
        }
        return y;
    }
};
```