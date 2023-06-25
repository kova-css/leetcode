#include <bits/stdc++.h>

using namespace std;

string defangIPaddr(string address) {
    string res = "";
    for (int i = 0; i < address.length(); i++) {
        if (address[i] == '.') {
            res += "[.]";
        }else {
            res += address[i];
        }
    }
    return res;
}

int main() {
    string address = "255.100.50.0";

    address = defangIPaddr(address);

    cout << address << endl;

    return 0;
}