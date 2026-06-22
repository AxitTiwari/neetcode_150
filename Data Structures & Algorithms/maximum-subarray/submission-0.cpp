class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = INT_MIN;
        dfs(0, 0, ans, nums);
        return ans;
    }
private:
    void dfs(int i, int cur_sum, int &ans, vector<int> &nums) {

        if (i == nums.size()) return ;

        cur_sum = max(nums[i], cur_sum + nums[i]);
        ans = max(ans, cur_sum);

        dfs(i+1, cur_sum, ans, nums);
    }
};
