class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> second_number;
        for (int i = 0; i < nums.size(); i++) {

            if (second_number.count(target - nums[i])) {
                vector<int> ans;
                if (i < second_number[target - nums[i]]) {
                    ans.push_back(i);
                    ans.push_back(second_number[target - nums[i]]);
                }
                else {
                    ans.push_back(second_number[target - nums[i]]);
                    ans.push_back(i);
                }
                return ans;
            }
            second_number[nums[i]] = i;
        }
        return {-1, -1};
    }
};
