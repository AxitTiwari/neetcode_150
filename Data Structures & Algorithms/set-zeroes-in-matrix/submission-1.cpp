class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {
                    set_row_col(matrix, i, j);
                }
            }
        }

        set_zero(matrix);
    }
private:

    void set_zero(vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == -1) matrix[i][j] = 0;
            }
        }
    }
    void set_row_col(vector<vector<int>>& matrix, int r, int c) {

        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[r][i] != 0) matrix[r][i] = -1;
        }

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][c] != 0) matrix[i][c] = -1;
        }
    }
};
