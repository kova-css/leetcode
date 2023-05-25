#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int first = 0, last = height.size()-1;
    int maxWater = 0;
    while (first < last) {
        int curWater;
        int minimum = min(height[first], height[last]);
        curWater = minimum * (last-first);
        height[first] > height[last] ? last-- : first++;
        if (curWater > maxWater) {
            maxWater = curWater;
        }
    }

    return maxWater;
}


int main() {
    vector<int> height = {1,2,1};
    cout << maxArea(height);

    return 0;
}