# Intuition
I first thought about running through the string until we find a character that the needle starts with. Then we compare character-by-character the upcoming chars to the chars of the needle, on a successful hit, we return the position.

# Approach
1. Iterate through each character of the **haystack** string using the index variable **i**.
2. Check if the current character **haystack[i]** matches the first character of the **needle** string, **needle[0]**.
3. If there is a match, assume that there is a potential occurrence of **needle** starting at index **i** in the **haystack** string.
4. Within the nested loop, starting from **j = 1**, compare the subsequent characters of **haystack** and **needle** to check for a complete match.
5. If at any point the characters do not match, set the **matches** flag to **false** and break out of the inner loop.
6. If all characters of **needle** match the corresponding characters in **haystack**, the **matches** flag will remain **true**.
7. If **matches** is **true**, return the starting index **pos** where the first occurrence of **needle** in **haystack** was found.
8. If **matches** is **false**, set **i** back to **pos** to resume the outer loop, continuing the search for the next potential occurrence.
9. If the end of the outer loop is reached without finding any occurrences, return **-1** to indicate that **needle** was not found in **haystack**.

# Complexity
- Time complexity:
$$O((n-m+1) * m)$$, where n is the length of the **haystack** string and m is the length of the **needle** string

- Space complexity:
$$O(1)$$

# Code
```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                bool matches = true;
                int pos = i;
                i++;
                for (int j = 1 ; j < needle.length(); j++) {
                    if (haystack[i] != needle[j]) {
                        matches = false;
                        break;
                    }
                    i++;
                }
                if (matches) {
                    return pos;
                }else {
                    i = pos;
                }
            }
        }
        return -1;
    }
};
```