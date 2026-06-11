class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                int key = i * grid[0].size() + j;

                if (grid[i][j] == '1' && !visited[key]) {
                    dfs(i, j, grid);
                    count += 1;
                }
            }
        }
        return count;
    }

private:
    unordered_map<int, bool> visited;
    void dfs(int x, int y, vector<vector<char>>& grid) {

        int key = x * grid[0].size() + y;
        visited[key] = true;

        vector<pair<int, int>> nbr = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (auto &[r, c] : nbr) {

            int new_x = x + r;
            int new_y = y + c;

            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;

            int new_key = new_x * grid[0].size() + new_y;
            if (!visited[new_key] && grid[new_x][new_y] == '1') {
                dfs(new_x, new_y, grid);
            }
        }
    }
};
