#include <bits/stdc++.h>

using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int ans = 0;
    int t[101] = {0};
    for (int i = 0; i < nums.size(); i++) {
        t[nums[i]]++;
    }
    for (int i = 0; i < 101; i++) {
        ans += t[i] * (t[i] - 1) / 2;
    }
    return ans;
}

int main() {

    return 0;
}