class Solution {
private:
    int f(int i, int buy, vector<int>& prices) {

        if (i >= prices.size()) {
            return 0;
        }

        int include = 0, exclude = 0;
        if (buy == 1) {

            include = -prices[i] + f(i+1, 0, prices);
            exclude = f(i+1, 1, prices);
        }
        else if (buy == 0){
            include = prices[i] + f(i+1, -1, prices);
            exclude = f(i+1, 0, prices);
        }

        cout << i << ": " << include << " or " << exclude << endl;
        return max(include, exclude);
    }

public:
    int maxProfit(vector<int>& prices) {
        
        return f(0, 1, prices);
    }
};
