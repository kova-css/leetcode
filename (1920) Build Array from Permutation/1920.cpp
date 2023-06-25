#include <bits/stdc++.h>

using namespace std;

vector<int> buildArray(vector<int>& nums) {
    int s = nums.size();

    for (int i = 0; i < s; i++) {
        nums[i] += s * (nums[nums[i]] % s);
    }

    for (int i = 0; i < s; i++) {
        nums[i] /= s;
    }

    return nums;
}

int main() {
    vector<int> nums = {0,2,1,5,3,4};

    nums = buildArray(nums);

    for (auto i : nums) {
        cout << i << " ";
    }

    return 0;
}