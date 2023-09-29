#include <bits/stdc++.h>

using namespace std;

bool isMonotonic(vector<int>& nums) {
    if (nums[nums.size() - 1] - nums[0] == 0) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                return false;
            }
        }
    }else if (nums[nums.size() - 1] - nums[0] > 0) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
    }else {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> nums = {1,2,2,3};
    cout << isMonotonic(nums) << endl;

    return 0;
}