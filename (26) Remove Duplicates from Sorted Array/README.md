# Intuition
My first implementation was to run through the array and when it finding a duplicate remove it and not increase K, but that wasn't really time efficient (it was in the worst 5%), so I decided to not delete elements, but instead replace them.

# Approach
1. Initialize a variable **k** to 1. This variable represents the position where the next unique element should be placed.
2. Start iterating over the array **nums** from the second element (index 1) using a pointer **i**.
3. Compare the current element **nums[i]** with the element at the position **k-1** (the last unique element encountered so far).
4. If **nums[i]** is not equal to **nums[k-1]**, it means a new unique element is found.
5. Assign the value of **nums[i]** to **nums[k]** to place the unique element at the correct position.
6. Increment **k** by 1 to move to the next available position for the next unique element.
7. Repeat steps 3-6 for the remaining elements in the array.
8. After the loop, the first **k** elements of the array will contain the unique elements, and **k** will represent the number of unique elements.
9. Return the value of **k**.

The approach utilizes two pointers, **i** and **k**, to traverse the array and keep track of the unique elements. The elements are shifted in-place to the beginning of the array, and the value of **k** is updated accordingly. This approach avoids the need for element removal using the **erase** function, resulting in an improved time complexity of O(n).

# Complexity
- Time complexity:
$$O(n)$$, where n is the length of the input array **nums**

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
```