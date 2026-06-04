class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        string value = "";
        
        vector<pair<string, int>> ans = mp[key];

        int s = 0, e = ans.size() - 1;
        while (s <= e) {

            int m = s + (e - s) / 2;

            auto &[val, t] = ans[m];

            if (t == timestamp) {
                return val;
            }
            else if (t > timestamp) {
                e = m - 1;
            }
            else {
                value = val;
                s = m + 1;
            }
        }
        return value;
    }
};
