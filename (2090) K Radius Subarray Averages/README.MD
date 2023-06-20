# Intuition
This has taken me a lot of tries as it always kept exceeding the time limit for some reason. This is actually the first real sliding door problem I've encountered outside of textbooks (at least of what I can remember) and this was fairly easy. Just think of scanner which scans k number of items and once and you move the scanner with every iteration.

# Approach
1. Create a vector **avgs** of size **n** to store the averages of subarrays.
2. Initialize **windowSum** as 0 to keep track of the sum of elements within the window.
3. Initialize **left** and **right** pointers to 0 to represent the boundaries of the sliding window.
4. Iterate the **right** pointer from 0 to n-1:
    - Add **nums[right]** to **windowSum**.
    - Check if the window size exceeds **2 * k** (i.e., **right - left + 1 > 2 * k**):
    - Calculate the average of the subarray centered at **left + k** using the formula **windowSum / (2 * k + 1)**.
    - Store the calculated average in **avgs[left + k]**.
    - Subtract **nums[left]** from **windowSum** to update the sum for the next window.
    - Increment **left** by 1 to shift the window to the right.
    - Increment **right** by 1 to expand the window to the right.
5. Return the **avgs** vector.

The approach uses a sliding window technique to efficiently calculate the averages of subarrays with a length of **2 * k + 1**. By updating the window sum and sliding the window, we can avoid redundant calculations and compute the averages in a single pass over the input array **nums**.

# Complexity
- Time complexity:
$$O(n)$$, where n is the size of the input array **nums**

- Space complexity:
$$O(n)$$, where n is the size of the input array **nums**

# Code
```c++
class Solution {
public:
    vector<int> getAverages(const vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);

        unsigned long windowSum = 0;
        int left = 0, right = 0;

        while (right < n) {
            windowSum += nums[right];

            if (right - left + 1 > 2 * k) {
                avgs[left + k] = windowSum / (2 * k + 1);
                windowSum -= nums[left];
                left++;
            }

            right++;
        }

        return avgs;
    }
};
```