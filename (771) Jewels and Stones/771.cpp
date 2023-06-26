#include <bits/stdc++.h>

using namespace std;

int numJewelsInStones(string jewels, string stones) {
    int ans = 0;
    for (int i = 0; i < jewels.length(); i++) {
        for (int j = 0; j < stones.length(); j++) {
            if (jewels[i] == stones[j]) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {


    return 0;
}