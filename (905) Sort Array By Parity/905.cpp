#include <bits/stdc++.h>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int scanner = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            int temp = nums[i];
            for (int j = i; j > scanner; j--) {
                nums[j] = nums[j-1];
            }
            nums[scanner] = temp;
            scanner++;
        }
    }
    return nums;
}

int main() {
    vector<int> nums = {3,1,2,4};

    vector<int> fin = sortArrayByParity(nums);
    
    for (auto i : fin) {
        cout << i << " ";
    }

    return 0;
}