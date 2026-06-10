class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        
        string para;
        dfs(0, 0, n, para);
        return res;
    }

private:
    void dfs(int countOpen, int countClose, int n, string &para) {

        if (countOpen + countClose == 2 * n) {
            res.push_back(para);
            return;
        }

        if (countOpen < n) {
            para += "(";
            dfs(countOpen+1, countClose, n, para);
            para.pop_back();
        }

        if (countClose < countOpen) {
            para += ')';
            dfs(countOpen, countClose+1, n, para);
            para.pop_back();
        }
    }
};
