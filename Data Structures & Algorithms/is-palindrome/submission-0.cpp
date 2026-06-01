class Solution {
public:
    bool isPalindrome(string str) {

        string clone;
        for (char s : str) {

            s = tolower(s);
            if ((s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) clone += s;
        }
        
        int s = 0, e = clone.length()-1;
        while (s < e) {

            if (clone[s] != clone[e]) return false;
            s++;
            e--;
        }
        return true;
    }
};
