class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        unordered_set<int> s;
        for (int &num : nums) {
            s.insert(num);
        }

        for (int i = 0; i <= nums.size(); i++) {

            if (s.find(i) == s.end()) return i;
        }
    }
};
