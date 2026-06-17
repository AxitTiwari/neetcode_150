class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        string ans = "";
        unordered_map<string, bool> dp;
        return func(ans, s, wordDict, dp);
    }
private:
    bool func(string &ans, string s, vector<string> &wordDict, unordered_map<string, bool> &dp) {

        if (ans == s) return true;

        if (ans.length() > s.length()) return false;

        if (dp.count(ans)) return dp[ans];

        for (int i = 0; i < wordDict.size(); i++) {

            ans += wordDict[i];

            if (s.compare(0, ans.size(), ans) == 0) {

                if (func(ans, s, wordDict, dp)) {
                    return dp[ans] = true;
                }
            }
            ans.erase(ans.length() - wordDict[i].length());
        }
        return dp[ans] = false;
    }
};