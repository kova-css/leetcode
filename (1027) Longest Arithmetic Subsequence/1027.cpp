#include <bits/stdc++.h>

using namespace std;

int longestArithSeqLength(vector<int>& A) {
    int n = A.size();
    int maxLen = 2;

    unordered_map<int, unordered_map<int, int>> dp;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int diff = A[i] - A[j];
            if (dp[j].count(diff)) {
                int prevLen = dp[j][diff];
                dp[i][diff] = prevLen + 1;
                maxLen = max(maxLen, dp[i][diff]);
            } else {
                dp[i][diff] = 2;
            }
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {3,6,9,12};

    cout << longestArithSeqLength(nums) << endl;

    return 0;
}