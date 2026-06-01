class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        for (auto str : strs) {

            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> ans(map.size());
        int i = 0;
        for (auto &it : map) {

            for (auto &same : it.second) {
                ans[i].push_back(same);
            }
            i++;
        }
        return ans;
    }
};
