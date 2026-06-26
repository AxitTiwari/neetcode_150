class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<vector<int>> c_triplets;
        for (int i = 0; i < triplets.size(); i++) {

            bool not_copy = false;
            for (int j = 0; j < triplets[0].size(); j++) {

                if (triplets[i][j] > target[j]) {
                    not_copy = true;
                    break;
                }
            }

            if (not_copy) continue;

            c_triplets.push_back(triplets[i]);
        }

        for (int i = 0; i < target.size(); i++) {

            bool found = false;
            for (int j = 0; j < c_triplets.size(); j++) {

                if (c_triplets[j][i] == target[i]) {
                    found = true;
                    break;
                }
            }

            if (!found) return false;
        }

        return true;
    }
};
