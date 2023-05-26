# Intuition
I first thout about simply counting opening and closing parenthesis but that turned out to be an incorrect solution as that didn't take into account the possibility of intersecting parenthesis. I then thought about collecting the openings into a stack and then comparing the tops with the closing ones.

# Approach
1. Create an empty stack of characters to store opening parentheses.
2. Iterate through each character in the input string.
3. For each character, check if it is an opening parenthesis ('(', '[', or '{'). If it is, push it onto the stack.
4. If the character is a closing parenthesis (')', ']', or '}'), check if the stack is empty. If it is, there is no matching opening parenthesis for the current closing parenthesis, indicating an invalid string. Return **false**.
5. If the stack is not empty, compare the current closing parenthesis with the top of the stack to check if they form a valid pair.
6. If the current closing parenthesis matches the top of the stack (e.g., ')' matches '('), pop the top element from the stack as they form a valid pair.
7. If the current closing parenthesis does not match the top of the stack, it means the parentheses are not balanced, indicating an invalid string. Return **false**.
8. After iterating through all the characters in the string, check if the stack is empty. If it is, all opening parentheses have been matched with their corresponding closing parentheses, indicating a valid string. Return **true**. Otherwise, if there are remaining opening parentheses in the stack, they are unmatched, indicating an invalid string. Return **false**.

The main idea behind this approach is to use a stack to keep track of opening parentheses encountered while iterating through the string. Whenever a closing parenthesis is encountered, it is checked against the top of the stack to ensure they form a valid pair. By maintaining the stack and checking its status at the end, you can determine if the string contains balanced parentheses.

# Complexity
- Time complexity:
$$O(n)$$, where n is the length of the input string **s**

- Space complexity:
$$O(n)$$, where n is the length of the input string **s**

# Code
```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
```