// Runtime: 4ms, 17.37%
// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    string toLowerAndRemoveNonAlphanumeric(string str) {
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return tolower(c);
        });

        str.erase(remove_if(str.begin(), str.end(), [](unsigned char c) {
            return !isalnum(c);
        }), str.end());

    return str;
    }

    bool isPalindrome(string s) {
        s = toLowerAndRemoveNonAlphanumeric(s);
        int i = 0;
        int j = s.size() - 1;
        while(i<j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
