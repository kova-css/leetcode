# Intuition
My first thought was to merge the vectors in another vector, then find the median value(s), then simply return it.

# Approach
1. Create an empty vector **merged** to store the merged sorted array.
2. Reserve enough capacity in the **merged** vector to accommodate all the elements from **nums1** and **nums2** to avoid unnecessary reallocations during the merge process.
3. Use the **merge** function from the C++ Standard Library's <**algorithm**> header to merge the two sorted arrays **nums1** and **nums2** into the **merged** vector. The **merge** function takes the iterators of the two arrays and the output iterator for the merged array. It performs a merge operation in a way that maintains the sorted order.
4. Calculate the median based on the merged array's size:
    - If the size of **merged** is even (**merged.size() % 2 == 0**), take the average of the two middle elements: **(double)(merged[merged.size()/2-1] + merged[merged.size()/2])/2**.
    - If the size of merged is odd, simply return the middle element: **merged[merged.size()/2]**.
5. Finally, return the calculated median.

# Complexity
- Time complexity:
$$O(n)$$, where n is the sum of the sizes of **nums1** and **nums2**.

- Space complexity:
$$O(n)$$, where n is the sum of the sizes of **nums1** and **nums2**.

# Code
```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merged.reserve(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));
        return merged.size() % 2 == 0 ? (double)(merged[merged.size()/2-1] + merged[merged.size()/2])/2 : merged[merged.size()/2];
    }
};
```