class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size() - 1;

        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n+1);
        for (int i = n; i >= 0; i--) {

            int curr = temperatures[i];

            while (s.top() != -1 && temperatures[s.top()] <= curr) {
                s.pop();
            }

            ans[i] = s.top() == -1 ? 0 : s.top() - i;
            s.push(i);
        }
        return ans;
    }
};
