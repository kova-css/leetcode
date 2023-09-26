# Intuition
I decided to use two vectors: one for character frequency and another to track whether a character is in the stack. By iterating through the string twice and using a stack, I could efficiently construct the desired result string.

# Approach
1. Initialize two vectors:
    - **freq** (frequency) of size 26 to count the occurrence of each character in the input string **s**.
    - **inStack** of size 26 to track whether a character is currently in the stack.
2. Create a stack called **result** to store the characters in the desired order.
3. Iterate through the characters of the input string **s**:
    - Increment the corresponding character's count in the **freq** vector.
4. Iterate through the characters of the input string **s** again:
    - Decrement the corresponding character's count in the **freq** vector.
    - Check if the character is already in the **result** stack (**inStack[c - 'a'] == true**). If so, skip this character.
5. For each character, while the stack is not empty, and the current character is smaller than the character at the top of the stack, and there are still occurrences of the character at the top of the stack remaining in the input string (**freq[result.top() - 'a'] > 0**), pop characters from the stack and mark them as not in the stack (**inStack[result.top() - 'a'] = false**).
6. Push the current character onto the **result** stack and mark it as in the stack.
7. After processing all characters, construct the final result string by popping characters from the stack and appending them to the beginning of **resultStr**.

# Complexity
- Time complexity:
$O(n)$, where n is the lenght of the input string **s**

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);
        stack<char> result;

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : s) {
            freq[c - 'a']--;

            if (inStack[c - 'a']) {
                continue;
            }

            while (!result.empty() && c < result.top() && freq[result.top() - 'a'] > 0) {
                inStack[result.top() - 'a'] = false;
                result.pop();
            }
            result.push(c);
            inStack[c - 'a'] = true;

        }

        string resultStr = "";
        while (!result.empty()) {
            resultStr = result.top() + resultStr;
            result.pop();
        }
        
        return resultStr;
    }
};
```