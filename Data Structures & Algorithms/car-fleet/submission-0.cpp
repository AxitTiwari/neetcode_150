class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        unordered_map<int, int> speed_of_car;
        for (int i = 0; i < position.size(); i++) {
            speed_of_car[position[i]] = speed[i];
        }

        sort(position.rbegin(), position.rend());

        vector<double> s;
        for (int i = 0; i < position.size(); i++) {

            int pos = position[i];
            double x = (target - pos) / (double)speed_of_car[pos];

            cout << x << endl;

            s.push_back(x);

            if (s.size() >= 2 && s.back() <= s[s.size()-2]) {
                s.pop_back();
            }
        }
        return s.size();
    }
};
