class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded;
        for (string str : strs) {
            encoded += str;
            encoded += '\0';
        }
        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> decoded;
        string str;
        for (auto ch : s) {

            if (ch != '\0') {
                str += ch;
            }
            else {
                decoded.push_back(str);
                str.clear();
            }
        }
        return decoded;
    }
};
