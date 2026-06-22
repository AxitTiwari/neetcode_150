class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums, dp);
    }
private:
    bool dfs(int i, vector<int> &nums, vector<int> &dp) {

        if (i == nums.size()-1) return true;

        if (dp[i] != -1) return dp[i];

        int start_from = i+nums[i] >= nums.size() ? nums.size()-1 : i+nums[i];
        for (int j = start_from; j > i; j--) {

            if (dfs(j, nums, dp)) return dp[i] = true;
        }
        return dp[i] = false;
    }
};
