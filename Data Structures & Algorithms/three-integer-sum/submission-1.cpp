class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            
            int left = i+1;
            int right = nums.size()-1;

            while (left < right) {

                if (nums[i] + nums[left] + nums[right] == 0) {
                    ans.insert({nums[i], nums[left], nums[right]});
                    left++, right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};
