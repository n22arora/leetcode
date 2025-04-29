#include <algorithm>

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char ch: s) {
            if (isalnum(ch)) {
                str += tolower(ch);
            }
        }

        string rev = str;

        reverse(str.begin(), str.end());

        return (rev == str);
    }
};

