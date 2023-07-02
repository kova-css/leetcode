# Intuition
We don't actually need to cound the words, only the spaces.

# Approach
1. Initialize a variable **maxwords** to keep track of the maximum number of words found in a sentence.
2. Iterate through each sentence in the **sentences** vector.
3. For each sentence, initialize a variable **temp** to keep track of the number of words found.
4. Iterate through each character in the sentence.
5. If a space character is encountered, increment **temp** to count the number of words.
6. Check if **temp** is greater than the current **maxwords**. If so, update **maxwords** with the new value.
7. Return the final value of **maxwords**.

# Complexity
- Time complexity:
$O(n*m)$, where n is the number of sentences and m is the average length of each sentence

- Space complexity:
$O(1)$

# Code
```c++
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxwords = 0;
        for (int i = 0; i < sentences.size(); i++) {
            int temp = 1;
            for (int j = 0; j < sentences[i].length(); j++) {
                if (sentences[i][j] == ' ') {
                    temp++;
                }
            }
            if (temp > maxwords) {
                maxwords = temp;
            }
        }
        return maxwords;
    }
};
```