# Intuition
These sliding doors and their time requirements maaan. I tried to make it work with a simple window which calculates the max every step but OF COURSE it ran into time constraints. Luckily there are these deque data types (how do you even pronounce this? DQ? Deck?) which to me are still these magical black boxes where I put in the values and somehow solves the problem.

# Approach
The code maintains a sliding window of size **k** using a deque (**window**). At each step, it performs the following operations:

1. Remove elements from the front of the deque that are no longer in the current window range (**i - k**).
2. Remove elements from the back of the deque that are smaller than the current element (**nums[i]**), as they are no longer candidates for the maximum in the window.
3. Add the current index **i** to the back of the deque.
4. If the current index **i** is greater than or equal to **k - 1** (indicating that the window has reached its full size), add the maximum element (at the front of the deque) to the result vector.

By using the deque, the code efficiently maintains the candidates for the maximum element in the sliding window, and the maximum element at each step can be accessed in constant time.

# Complexity
- Time complexity:
$O(n)$, where n is the size of the input vector nums

- Space complexity:
$O(k)$, where k is the size of the sliding window

# Code
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            while (!window.empty() && window.front() <= i - k)
                window.pop_front();

            while (!window.empty() && nums[window.back()] < nums[i])
                window.pop_back();

            window.push_back(i);

            if (i >= k - 1)
                result.push_back(nums[window.front()]);
        }

        return result;
    }
};
```