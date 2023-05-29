# Intuition
This was quite simple, as it was obvious that we needed to simply binary search the position of the element, and if not found just return the last search as the target would be placed there.

# Approach
1. Initialize **start** as 0, representing the starting index of the search range, and **stop** as **nums.size()-1**, representing the ending index of the search range.
2. Enter a **while** loop that continues as long as **start** is less than or equal to **stop**.
3. Inside the loop, calculate the middle position **middlePos** as the average of **start** and **stop**.
4. Retrieve the middle element value **middleInt** from the **nums** array using **nums[middlePos]**.
5. Compare **middleInt** with the **target** value:
    - If they are equal, the **target** is found at the middle position. Return **middlePos**.
    - If **middleInt** is greater than **target**, update **stop** to **middlePos-1** to search the left half of the array.
    - If **middleInt** is less than **target**, update **start** to **middlePos+1** to search the right half of the array.
6. If the **while** loop completes without finding the exact **target**, it means the target does not exist in the array. In this case, the correct insert position is at **start**. Return **start**.

The binary search approach efficiently divides the search range in half at each step, reducing the search space until the target element is found or the search range is exhausted.

# Complexity
- Time complexity:
$$O(log n)$$, where n is the number of elements in the **nums** array
    - Beats:
    **100%**
- Space complexity:
$$O(1)$$
    - Beats:
    **67.62%**
# Code
```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, stop = nums.size()-1;
        while (start <= stop) {
            int middlePos = (start+stop)/2;
            int middleInt = nums[middlePos];
            if (middleInt == target) {
                return middlePos;
            }else if (middleInt > target) {
                stop = middlePos-1;
            }else {
                start = middlePos+1;
            }
        }
        return start;
    }
};
```