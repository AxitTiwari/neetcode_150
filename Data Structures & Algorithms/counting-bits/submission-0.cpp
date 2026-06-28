class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(hammingWeight(i));
        }
        return ans;
    }
private:
    int hammingWeight(int n) {
        
        int ans = 0;
        while (n > 0) {

            if (n & 1) ans++;

            n = n >> 1;
        }
        return ans;
    }
};
