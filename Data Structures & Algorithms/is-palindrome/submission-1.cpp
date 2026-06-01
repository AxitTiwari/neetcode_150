class Solution {
public:
    bool isPalindrome(string str) {

        int s = 0, e = str.length()-1;

        while (s < e) {

            while (!isalnum(str[s])) s++;
            while (!isalnum(str[e])) e--;

            if (s < e && tolower(str[e]) != tolower(str[s])) return false;
            s++;
            e--;
        }
        return true;
    }
};
