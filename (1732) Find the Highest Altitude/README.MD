# Intuition
Easiest daily fr that's all I'm saying

# Approach
1. Initialize two variables, **alt** and **maxAlt**, to keep track of the current altitude and the maximum altitude encountered so far. Set both variables to 0 initially.
2. Iterate through the **gain** vector using a loop.
3. In each iteration, add the current gain value to the **alt** variable, representing the altitude change. This is done by incrementing **alt** with **gain[i]**.
4. Check if the current altitude, represented by **alt**, is greater than the maximum altitude encountered so far, represented by **maxAlt**.
    - If **alt** is greater than **maxAlt**, update **maxAlt** with the value of **alt**.
5. Repeat steps 3-4 for all elements in the **gain** vector.
6. After the loop finishes, return the value of **maxAlt**, which represents the highest altitude reached.

# Complexity
- Time complexity:
$$O(n)$$, where n is the length of the **gain** vector

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, maxAlt = 0;
        for (int i = 0; i < gain.size(); i++) {
            alt += gain[i];
            if (alt > maxAlt) {
                maxAlt = alt;
            }
        }
        return maxAlt;
    }
};
```