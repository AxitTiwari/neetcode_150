class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans;
        for (int i = 0; i < temperatures.size(); i++) {

            int days = 0;
            bool found = false;
            for (int j = i+1; j < temperatures.size(); j++) {

                if (temperatures[i] >= temperatures[j]) {
                    days++;
                }
                else {
                    days++;
                    found = true;
                    break;
                }
            }
            if (found) ans.push_back(days);
            else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};
