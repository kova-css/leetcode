# Intuition
At first I thought about using part of the paranthesis checker from the last problem but I quickly realized that I needed a new algorithm for this, but I had no clue how to start. I was reading the discussion when I saw someone post a tree graph of the possibilities of one of the samples and I thought, okay, it's possible with backtracking.

# Approach
1. Create a helper function called **backtrack** that takes the following parameters: **result** (a vector of strings to store valid parentheses combinations), **current** (a string representing the current combination of parentheses), **open** (the count of open parentheses), **close** (the count of close parentheses), and **n** (the desired number of pairs of parentheses).
2. The base case of the recursion is when the length of the **current** string is equal to **2 * n**. In this case, all open and close parentheses have been used, so the **current** string represents a valid combination of parentheses. Add the **current** string to the **result** vector and return.
3. If the count of open parentheses (**open**) is less than **n**, it means there are still available open parentheses. Append an opening parenthesis '(' to the **current** string and make a recursive call to **backtrack**, incrementing **open** by 1. This explores the possibility of using an open parenthesis at this position.
4. If the count of close parentheses (**close**) is less than **open**, it means there are more open parentheses than close parentheses in the **current** string. Append a closing parenthesis ')' to the **current** string and make a recursive call to **backtrack**, incrementing close by 1. This explores the possibility of using a **close** parenthesis to match an existing open parenthesis.
5. After each recursive call, remove the last character from the **current** string to revert it back to the previous state. This is necessary to explore other possibilities and combinations.
6. Call the **backtrack** function initially with an empty **current** string, and both **open** and **close** counts set to 0.
7. Finally, return the **result** vector containing all valid combinations of parentheses.

The backtracking algorithm explores all possible combinations of parentheses by making recursive calls, adding opening parentheses when there are still available, and adding closing parentheses when there are more openings than closings. This guarantees that all valid combinations of parentheses of length 2 * n are generated.

# Complexity
- Time complexity:
$$O(C(n))$$, where $$C(n)$$ is the Catalan number, which is approximately $$4^n/n^{3/2}$$

- Space complexity:
$$O(C(n))$$, where $$C(n)$$ is the Catalan number, which is approximately $$4^n/n^{3/2}$$
# Code
```c++
class Solution {
public:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back();
        }
        
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        
        backtrack(result, current, 0, 0, n);
        
        return result;
    }
};
```