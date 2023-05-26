# Intuition
This one took a bit of time. I first though about counting characters in individual strings and then lifting them out of the vector one-by-one by matching the character counts. After some trial and error I got that to work but realized that that took too much time, so I needed a new plan. I thought about sorting the characters in the string and then would've only needed to compare the string, not the characters, but for this method I needed to change the character counting method to a map. This turned out to be very time and space efficient compared to others, being in the top 5% of LeetCode submissions.

# Approach
1. Create an unordered map called **groups**, where the keys will represent the sorted versions of the anagrams, and the values will be vectors of strings that belong to the same anagram group.
2. Iterate through each string in the input vector **strs**.
3. For each string, create a copy called **sortedStr** and sort its characters in ascending order using the **sort** function. This step ensures that anagrams have the same sorted representation.
4. Use the sorted string **sortedStr** as the key in the **groups** map. If the key doesn't exist in the map, a new entry is automatically created with an empty vector as the value. If the key already exists, the corresponding vector is accessed.
5. Push the original unsorted string **str** into the vector associated with the key **sortedStr**. This step groups the anagrams together.
6. After iterating through all the strings, create a **vector<vector<string>>** called **result** to store the grouped anagrams.
7. Iterate through each key-value pair in the **groups** map. For each pair, access the vector of anagrams (the value) and push it into the **result** vector.
8. Return the **result** vector, which contains the anagram groups.

The main idea behind this approach is to use the sorted representation of each string as the key in an unordered map. By grouping the original unsorted strings together based on their sorted versions, you can efficiently group the anagrams. The final result is a vector of vectors, where each inner vector represents a group of anagrams.

# Complexity
- Time complexity:
$$O(N * K log K)$$, where N is the total number of strings in the input vector **strs** and K is the average length of the strings

- Space complexity:
$$O(N * K)$$, where N is the number of strings and K is the average length of the strings

# Code
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            groups[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};
```