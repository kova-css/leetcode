# Intuition
I first thought about taking the first word and calling it prefix, then comparing character-by-character to the next until it differs, then updating that prefix to the character chain that matched. I understand there was a solution which iterates through all the words comparing the characters which taking in account the 200 word limit is also feasible, but I decided to implement a more efficient algorithm.

# Approach
1. Initialize the **prefix** variable with the first word in the input vector **strs**. This assumes that there is at least one word in the vector. If the **prefix** is an empty string, return an empty string as there can be no common prefix.
2. Iterate through the remaining words in the **strs** vector using a for loop, starting from index 1.
3. For each word, check if it is equal to the **prefix**. If they are equal, it means the current word shares the same prefix as the previous words, so you continue to the next iteration.
4. If the current word is not equal to the **prefix**, enter a while loop that compares each character of the current word and the **prefix**. The loop continues as long as the characters match, and you build the **nextWord** string by appending the matching characters.
5. If **nextWord** is an empty string after the while loop, it means there is no common prefix between the current word and the **prefix**, so return an empty string.
6. Otherwise, update the **prefix** to be the **nextWord** and continue to the next iteration of the loop.
7. After the loop completes, return the final prefix, which represents the longest common **prefix** among all the words in the **strs** vector.

The main idea behind this approach is to use the first word in the vector as the initial prefix and compare it with the subsequent words. By iterating through the words and comparing characters, you gradually build the common prefix. If at any point there is no common prefix, an empty string is returned. The approach efficiently finds the longest common prefix by comparing characters one by one until a mismatch occurs.

# Complexity
- Time complexity:
$$O(n*m)$$, where n is the number of words in the input vector **strs** and m is the average length of the words

- Space complexity:
$$O(m)$$, where m is the length of the longest common prefix

# Code
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs.front();
        if (prefix == "") {
            return "";
        }
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i] == prefix) {
                continue;
            }
            int iter = 0;
            string nextWord = "";
            while (strs[i][iter] == prefix[iter]) {
                nextWord += strs[i][iter];
                iter++;
            }
            if (nextWord == "") {
                return "";
            }
            prefix = nextWord;
        }
        return prefix;
    }
};
```