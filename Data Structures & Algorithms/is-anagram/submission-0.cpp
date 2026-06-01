class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<char> countS(26, 0);
        vector<char> countT(26, 0);

        for (char ch : s) {
            countS[ch - 'a']++;
        }

        for (char ch : t) {
            countT[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (countS[i] != countT[i]) return false;
        }
        return true;
    }
};
