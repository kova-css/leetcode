# Intuition
Just followed the instructions 🤷

# Approach
1. You can simple return the calculations in curly braces

# Complexity
- Time complexity:
$O(1)$

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
```