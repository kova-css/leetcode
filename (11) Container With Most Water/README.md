# Intuition
I first thought about taking 2 pointers, one for the 0th and one for the last element, then I would iterate them closer until the next column was smaller, but this seemed to only work in a small number of cases. For my final solution I had kept the 2 pointers, but I would calculate the water at every step and would only iterate the pointer with the smaller column, this seemed to do the trick.

# Approach
1. Initialize two pointers, **first** and **last**, to the first and last indices of the input array **height**.
2. Initialize a variable **maxWater** to 0, which will store the maximum area of water found so far.
3. Start a while loop that continues until the **first** pointer is less than the **last** pointer. This loop will iterate through all possible pairs of lines to calculate the water area between them.
4. Inside the loop, calculate the current water area by finding the minimum height between the two pointers (**minimum = min(height[first], height[last])**) and multiplying it by the distance between the pointers (**curWater = minimum * (last - first)**).
5. Check if the current water area **curWater** is greater than the maximum water area found so far **maxWater**. If it is, update **maxWater** with the new maximum value.
6. Compare the heights of the lines at the **first** and **last** indices. If the height at **first** is greater than the height at **last**, it means that moving the **last** pointer inward will not give a greater water area. Therefore, decrement the **last** pointer. Otherwise, increment the **first** pointer.
7. Once the while loop completes, return the maximum water area **maxWater**.


The intuition behind this approach is that the water area between two lines is limited by the shorter line and the distance between them. By starting with the widest container (using the first and last lines) and gradually narrowing it down by moving the pointers, we ensure that we explore all possible combinations of lines and find the maximum water area.

The two-pointer technique optimizes the solution by avoiding unnecessary calculations and reducing the time complexity to $$O(n)$$, where n is the size of the input array height.

# Complexity
- Time complexity:
$$O(n)$$,  where **n** is the number of elements in **height**

- Space complexity:
$$O(1)$$

# Code
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size()-1;
        int maxWater = 0;
        while (first < last) {
            int curWater;
            int minimum = min(height[first], height[last]);
            curWater = minimum * (last-first);
            if (height[first] > height[last]) {
                last--;
            }else {
                first++;
            }
            if (curWater > maxWater) {
                maxWater = curWater;
            }
        }

        return maxWater;
    }
};
```