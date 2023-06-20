#include <bits/stdc++.h>

using namespace std;

int largestAltitude(vector<int>& gain) {
    int alt = 0, maxAlt = 0;
    for (int i = 0; i < gain.size(); i++) {
        alt += gain[i];
        if (alt > maxAlt) {
            maxAlt = alt;
        }
    }
    return maxAlt;
}


int main() {
    vector<int> gain = {-5,1,5,0,-7};


    cout << largestAltitude(gain) << endl;
    return 0;
}
