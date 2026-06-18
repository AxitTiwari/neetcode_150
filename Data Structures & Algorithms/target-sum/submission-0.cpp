class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return func(0, target, nums);
    }
private:
    int func(int i, int amount, vector<int> &nums) {

        if (i == nums.size()) return amount == 0 ? 1 : 0;

        // cout << amount << " " ;

        int add = func(i+1, amount-nums[i], nums);
        int sub = func(i+1, amount+nums[i], nums);

        return add + sub;
    }
};