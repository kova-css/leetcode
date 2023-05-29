#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutation, vector<bool>& used) {
    if (permutation.size() == nums.size()) {
        result.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) {
            continue;
        }

        permutation.push_back(nums[i]);
        used[i] = true;

        backtrack(nums, result, permutation, used);

        permutation.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);

    backtrack(nums, result, permutation, used);

    return result;
}


int main() {
    vector<int> nums = {1,2,3};
    permute(nums);
    return 0;
}