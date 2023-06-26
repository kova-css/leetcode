#include <bits/stdc++.h>

using namespace std;

vector<int> leftRightDifference(vector<int>& nums) {
    int sizes = nums.size();
    vector<int> left(sizes), right(sizes);
    for (int i = 1; i < sizes; i++) {
        left[i] = left[i-1] + nums[i-1];
    }
    for (int i = sizes-2; i >= 0; i--) {
        right[i] = right[i+1] + nums[i+1];
    }
    for (int i = 0; i < sizes; i++) {
        left[i] = abs(left[i] - right[i]);
    }
    return left;
}

int main() {

    vector<int> nums = {10,4,8,3};

    nums = leftRightDifference(nums);

    for (auto i : nums) {
        cout << i << " ";
    }

    return 0;
}