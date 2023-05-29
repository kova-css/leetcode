#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start = 0, stop = nums.size()-1;
    while (start <= stop) {
        int middlePos = (start+stop)/2;
        int middleInt = nums[middlePos];
        if (middleInt == target) {
            return middlePos;
        }else if (middleInt > target) {
            stop = middlePos-1;
        }else {
            start = middlePos+1;
        }
    }
    return start;
}

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 4;
    cout << searchInsert(nums, target);

    return 0;
}