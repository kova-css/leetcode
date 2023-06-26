#include <bits/stdc++.h>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> shuffle(n*2);
    for (int i = 0; i < n*2; i+=2) {
        shuffle[i] = nums[i/2];
        shuffle[i+1] = nums[i/2+n];
    }
    return shuffle;
}

int main() {

    int n = 3;
    vector<int> nums = {2,5,1,3,4,7};

    nums = shuffle(nums, n);

    for (auto i : nums) {
        cout << i << " ";
    }

    return 0;
}