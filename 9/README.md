# Intuition
I first thought about converting the int to a string and then comparing the first and last characters, but it seemed too easy, so I decided to challange myself. I first thought about comparing the first and last digits then slicing them but that would've brought up problems with 0s, so I decided to run through the number without slicing it.

# Approach
The code starts by handling special cases where the integer is 0 or negative. If the integer is 0, it is considered a palindrome since it reads the same forwards and backward, so the code immediately returns true. If the integer is negative, it cannot be a palindrome since palindromes are usually defined for positive numbers, so the code returns false.

Next, the code calculates the size (number of digits) of the integer using logarithm and exponentiation operations. This step determines the number of iterations required to compare the digits.

The code then enters a loop that iterates from i = 0 to size/2. This iteration compares the digits from both ends of the integer. It utilizes mathematical operations like modulo and division to extract the corresponding digits from the integer.

Within the loop, the code calculates the last digit and the first digit. The last digit is obtained by taking the remainder of the integer divided by a power of 10, while the first digit is obtained by dividing the integer by a value based on the size of the integer.

The code then compares the first and last digits. If they don't match, it means the integer is not a palindrome, and the code returns false immediately. If the digits match, the loop continues to the next iteration.

After the loop completes without returning false, it indicates that all the digits from both ends of the integer matched, and thus, the integer is a palindrome. The code returns true to signify that the given integer is a palindrome.

# Complexity
- Time complexity:
$$O(log10(x))$$

- Space complexity:
$$O(1)$$

# Code
```
class Solution {
public:

    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0) {
            return false;
        }
        int size = log10(x)+1;
        int sizeAlt = pow(10,size-1);
        for (int i = 0; i < size/2; i++) {
            int last = pow(10, (i+1));
            int lastDigit = (x % last) / pow(10, i);
            int first = ((int) (x / (sizeAlt / pow(10, i)))) % 10;
            if (first != lastDigit) {
                return false;
            }                        
        }
        return true;
    }
};
```
