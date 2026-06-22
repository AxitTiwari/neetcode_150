class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        return dfs(0, nums);
    }
private:
    bool dfs(int i, vector<int> &nums) {

        if (i == nums.size()-1) return true;

        int start_from = i+nums[i] >= nums.size() ? nums.size()-1 : i+nums[i];
        for (int j = start_from; j > i; j--) {

            if (dfs(j, nums)) return true;
        }
        return false;
    }
};
