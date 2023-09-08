# Intuition
First we need to separete 2 edge cases where only the number 1 is present, then we can procedurally generate the middle of the triangle using the previous row of the stack.

# Approach
1. Initialize an empty vector of vectors called **fin** to store the Pascal's Triangle.
2. Create two vectors, **row** and **rowNxt**, to represent the current row and the next row in the triangle.
3. If **numRows** is greater than 0, create the first row with a single element, which is 1, and add it to **fin**.
4. If **numRows** is greater than 1, create the second row with two elements, both 1s, and add it to **fin**.
5. Use a loop to generate the remaining rows from the third row to the **numRows**-th row:
    - Initialize **rowNxt** with the first element as 1.
    - Use another loop to calculate the elements between the first and last element of the current row (**row**) by summing the corresponding elements from the previous row (**row**) and add these elements to **rowNxt**.
    - Add the last element of 1 to **rowNxt**.
    - Update **row** with the values from **rowNxt**.
    - Clear **rowNxt**.
    - Add the generated **row** to **fin**.
6. Return the **fin** vector containing Pascal's Triangle.

# Complexity
- Time complexity:
$O(n^2)$, where **n** is the value of the **numRows** parameter.

- Space complexity:
$O(n^2)$, where **n** is the value of the **numRows** parameter.

# Code
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> fin;
        vector<int> row, rowNxt;
        if (numRows > 0) {
            row.push_back(1);
            fin.push_back(row);
        }else {
            return fin;
        }
        if (numRows > 1) {
            row.push_back(1);
            fin.push_back(row);
        }else {
            return fin;
        }
        for (int i = 3; i < numRows+1; i++) {
            rowNxt.push_back(1);
            for (int j = 0; j < i-2; j++) {
                rowNxt.push_back(row[j]+row[j+1]);
            }
            rowNxt.push_back(1);
            row = rowNxt;
            rowNxt.clear();
            fin.push_back(row);
        }
        return fin;
    }
};
```