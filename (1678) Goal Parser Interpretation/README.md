# Intuition
We can simply evaluate the characters and construct a new string.

# Approach
1. Initialize an empty string **fin** to store the final interpreted command.
2. Iterate over each character in the input **command** string.
    - If the current character is 'G', append 'G' to the **fin** string.
    - If the current character is '(', check the next character:
        - If the next character is ')', it represents the command "( )". Append "o" to the **fin** string and increment the index **i** by 1.
        - If the next character is not ')', it represents the command "(al)". Append "al" to the **fin** string and increment the index **i** by 3.
3. Return the **fin** string as the interpreted command.

# Complexity
- Time complexity:
$O(n)$, where n is the length of the input string **command**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
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
};
```