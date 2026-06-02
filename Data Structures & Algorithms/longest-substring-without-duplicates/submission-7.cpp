class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int max_len = 0;

        unordered_map<int, pair<bool, int>> mp;
        
        int left = 0;
        bool is_duplicate = false;
        int remaing_len = 0;
        for (int right = 0; right < s.length(); right++) {

            if (mp[s[right]].first) {

                max_len = max(max_len, right - left);

                // ##imp
                left = max(left, mp[s[right]].second + 1);

                mp[s[right]].second = right;

                remaing_len = 0;
                continue;
            }

            remaing_len++;
            mp[s[right]] = {true, right};
        }
        return max_len + remaing_len;
    }
};
