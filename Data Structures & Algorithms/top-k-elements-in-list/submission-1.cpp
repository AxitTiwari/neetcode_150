class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> count;
        for (auto num : nums) {
            count[num]++;
        }

        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto &[num, cnt] : count) {

            min_heap.push({cnt, num});

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> ans;
        while (!min_heap.empty()) {

            auto [cnt, num] = min_heap.top();
            min_heap.pop();

            ans.push_back(num);
        }
        return ans;
    }
};
