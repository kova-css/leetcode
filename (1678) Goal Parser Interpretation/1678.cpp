#include <bits/stdc++.h>

using namespace std;

string interpret(string command) {
    string fin = "";
    for (int i = 0; i < command.length(); i++) {
        if (command[i] == 'G') {
            fin += 'G';
        }else if (command[i] == '(') {
            if (command[i+1] == ')') {
                fin += "o";
                i++;
            }else {
                fin += "al";
                i+=3;
            }
        }
    }
    return fin;
}

int main() {
    string command = "G()()()()(al)";
    command = interpret(command);
    cout << command << endl;
    return 0;
}