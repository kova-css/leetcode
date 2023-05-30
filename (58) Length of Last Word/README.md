# Intuition
I first sheepishly thought of just walking through the string and finding the last word and I've realized embarrasingly late that I should do that from the back which would be way easier and faster, so I did just that, I skipped the looming spaces, and counted the chars until another space appeared or the string ended.

# Approach
1. Initialize a variable **it** to the last index of the input string **s**.
2. Iterate backwards from the last index while the character at **it** is a space. Decrement **it** until a non-space character is encountered.
3. Initialize a variable **len** to 0 to store the length of the last word.
4. While **it** is a valid index and the character at **it** is not a space:
    - Increment **len** to count the character.
    - If **it** is not the first character, decrement **it** to move to the previous character.
    - If **it** is the first character, return **len**.
5. Return **len** as the length of the last word.

This approach finds the length of the last word by iterating backwards from the end of the string and counting the characters until a space or the beginning of the string is reached.

# Complexity
- Time complexity:
$$O(n)$$
    - Beats:
    **100%**

- Space complexity:
$$O(1)$$
    - Beats:
    **90.62%**

# Code
```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int it = s.length() - 1;
        while (s[it] == ' ') it--;
        int len = 0;
        while (s[it] && s[it] != ' ') {
            len++;
            if (it != 0) {
                it--;
            }else {
                return len;
            }
        }
        return len;
    }
};
```