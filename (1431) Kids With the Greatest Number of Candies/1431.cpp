#include <bits/stdc++.h>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int max = *max_element(candies.begin(), candies.end());
    vector<bool> result(candies.size());
    for (int i = 0; i < candies.size(); i++) {
        result[i] = candies[i] + extraCandies >= max ? true : false;
    }
    return result;
}

int main() {


    return 0;
}