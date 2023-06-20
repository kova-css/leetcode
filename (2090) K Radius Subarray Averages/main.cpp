#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> avgs(n, -1);

    long long windowSum = 0;
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

int main() {
    vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;

    nums = getAverages(nums, k);
    for (auto i : nums) {
        cout << i << " ";
    }

    return 0;
}
