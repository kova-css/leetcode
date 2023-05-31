#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> contains;
    for (auto itr : nums) {
        contains[itr]++;
    }

    for (auto itr : contains) {
        if (itr.second > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    
    vector<int> nums = {1,2,3,4,5,6,7,7,8};
    cout << containsDuplicate(nums);

    return 0;
}