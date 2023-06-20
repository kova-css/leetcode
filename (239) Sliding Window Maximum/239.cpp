#include <bits/stdc++.h>

using namespace std;

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

int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    nums = maxSlidingWindow(nums, k);

    for (auto i : nums) {
        cout << i << " ";
    }

    return 0;
}