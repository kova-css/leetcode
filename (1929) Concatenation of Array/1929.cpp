#include <bits/stdc++.h>

using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    int s = nums.size();
    for (int i = 0 ; i < s; i++) {
        nums.push_back(nums[i]);
    }
    return nums;
}

int main() {

    vector<int> nums = {1,2,1};

    nums = getConcatenation(nums);

    for (auto i : nums) {
        cout << i << " ";
    }

    return 0;
}