class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size()-1;

        vector<bool> is_possible(nums.size(), false);
        is_possible[n] = true;

        for (int i = n-1; i >= 0; i--) {

            int jumped = i + nums[i] >= nums.size() ? n : i + nums[i];
            for (int j = jumped; j > i; j--) {
                if (is_possible[j]) {
                    is_possible[i] = true;
                    break;
                }
            }
        }
        return is_possible[0];
    }
};
