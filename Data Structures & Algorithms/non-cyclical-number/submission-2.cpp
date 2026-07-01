class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> st;
        while (n != 1) {

            int sum = get_digit_sum(n);

            if (st.find(sum) != st.end()) break;
            
            st.insert(sum);

            cout << n << " ";

            n = sum;
        }
        return n == 1;
    }
private:
    int get_digit_sum(int n) {

        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
};
