class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {

            unordered_map<int, int> count;

            int len = 0;
            for (int j = i; j < s.length(); j++) {

                if (count[s[j]] > 0) {
                    break;
                }

                len++;
                count[s[j]]++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
