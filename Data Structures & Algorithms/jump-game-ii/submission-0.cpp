class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size() - 1;

        vector<int> min_jump(nums.size(), -1);
        min_jump[n] = 0;

        for (int i = n-1; i >= 0; i--) {

            int jumped_idx = i + nums[i] >= nums.size() ? nums.size()-1 : i + nums[i];
            for (int j = jumped_idx; j > i; j--) {

                if (min_jump[j] != -1) {
                    min_jump[i] = min_jump[i] != -1 ? min(min_jump[i], min_jump[j] + 1) : min_jump[j] + 1;
                }
            }
        }
        return min_jump[0];
    }
};
