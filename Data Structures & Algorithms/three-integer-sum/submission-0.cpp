class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> num_idx;
            for (int j = i+1; j < nums.size(); j++) {
                
                if (num_idx.count(-nums[i] - nums[j])) {
                    ans.insert({nums[i], nums[j], -nums[i] - nums[j]});
                }
                num_idx[nums[j]] = j;
            }
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};
