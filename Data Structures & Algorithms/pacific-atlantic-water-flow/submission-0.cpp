class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> res;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {

                unordered_map<int, bool> visited;
                bool reached_pacific = dfs(i, j, INT_MAX, true, visited, heights);

                visited.clear();
                bool reached_atlantic = dfs(i, j, INT_MAX, false, visited, heights);

                if (reached_pacific && reached_atlantic) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    bool dfs(int x, int y, int height, bool is_pacific, unordered_map<int, bool> &visited, vector<vector<int>>& heights) {

        int key = x * heights[0].size() + y;

        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || visited[key]) return false;

        if (height < heights[x][y]) return false;

        if (is_pacific && (y == 0 || x == 0)) return true;

        if (!is_pacific && (y == heights[0].size()-1 || x == heights.size()-1)) return true;

        visited[key] = true;

        return dfs(x+1, y, heights[x][y], is_pacific, visited, heights) ||
            dfs(x, y+1, heights[x][y], is_pacific, visited, heights) ||
            dfs(x-1, y, heights[x][y], is_pacific, visited, heights) ||
            dfs(x, y-1, heights[x][y], is_pacific, visited, heights);
    }

};