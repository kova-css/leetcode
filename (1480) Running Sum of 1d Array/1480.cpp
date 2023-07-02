#include <bits/stdc++.h>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int carry = 0;
    for (int i = 0; i < nums.size(); i++) {
        carry += nums[i];
        nums[i] = carry;
    }
    return nums;
}

int main() {
    cout << "aaa" << endl;

    return 0;
}