class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                int key = i * grid[0].size() + j;

                if (grid[i][j] == 1) {
                    area = max(area, 1 + dfs(i, j, grid));
                }
            }
        }
        return area;
    }
private:
    int dfs(int x, int y, vector<vector<int>>& grid) {

        // visited
        grid[x][y] = 0;

        vector<pair<int, int>> nbr = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int area = 0;
        for (auto &[r, c] : nbr) {

            int new_x = x + r;
            int new_y = y + c;

            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;

            if (grid[new_x][new_y] == 1) {
                area += 1 + dfs(new_x, new_y, grid);
            }
        }
        return area;
    }
};