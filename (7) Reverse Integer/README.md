# Intuition
This one was fairly simple, we even did this in school. The main difference was that this problem required that the answer was in a 32-bit limit. The main idea is that we have a new empty number and just one-by-one place the last digit of the original to the end of the new one.

# Approach
1. Initialize a variable **y** to store the reversed integer, initially set to 0.
2. Check if the input integer **x** is negative. If it is, set a boolean variable **minus** to true and convert **x** to its absolute value.
3. In a while loop, iterate until **x** becomes 0. In each iteration:
    - Multiply **y** by 10 and add the last digit of **x** (obtained by **x % 10**) to **y**.
    - Update **x** by integer division (**x /= 10**) to remove the last digit.
4. After the loop, check if the reversed integer **y** exceeds the range of 32-bit signed integer (**INT32_MIN** and **INT32_MAX**). If it does, return 0.
5. Return the reversed integer **y** as the result. If the original number was negative, multiply **y** by -1.

The approach involves extracting the digits from the input integer **x** one by one using modulo operations, then constructing the reversed integer **y** by multiplying it by 10 and adding the next digit. Finally, the range of the resulting reversed integer is checked, and the appropriate sign is applied based on the original number.

It's worth noting that the code uses a **long long** data type for **y** to handle cases where the reversed integer might exceed the range of a 32-bit integer during the intermediate calculations.

# Complexity
- Time complexity:
$$O(log10(x))$$, where x is the input integer

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
    long long reverse(long long x) {
        long long y = 0;
        bool minus = false;
        if (x < 0) {
            minus = true;
            x = -x;
        }
        while (x > 0) {
            y = y * 10 + (x % 10);
            x/=10;
        }
        if (y < INT32_MIN || y > INT32_MAX) {
            return 0;
        }
        return minus ? -y : y;
    }
};
```