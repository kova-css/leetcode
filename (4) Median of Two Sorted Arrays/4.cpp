#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    merged.reserve(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));
    return merged.size() % 2 == 0 ? (double)(merged[merged.size()/2-1] + merged[merged.size()/2])/2 : merged[merged.size()/2];
}


int main() {

    vector<int> nums1 = {1,2}, nums2 = {3,4};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}