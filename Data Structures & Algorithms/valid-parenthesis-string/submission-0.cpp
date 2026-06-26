#include <bits/stdc++.h>
class Solution {
public:
    bool checkValidString(string s) {
        
        memset(dp, -1, sizeof(dp));
        return func(0, 0, s);
    }
private:

    int dp[101][101];
    bool func(int i, int open, string &s) {

        if (i >= s.length()) {
            
            return open == 0;
        }

        if (dp[i][open] != -1) return dp[i][open];

        if (s[i] == '(') {
            return dp[i][open] = func(i+1, open+1, s);
        }
        else if (s[i] == ')' and open >= 1) {

            return dp[i][open] = func(i+1, open-1, s);
        }
        else {

            if (s[i] == ')') return false;

            bool a = func(i+1, open+1, s);

            bool b = false;
            if (open >= 1)
                b = func(i+1, open-1, s);

            bool c = func(i+1, open, s);

            return dp[i][open] = a or b or c;
        }
    }
};
