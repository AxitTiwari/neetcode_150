class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {

        parent.resize(n+1);
        size.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_size(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return;

        if (size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();

        vector<pair<int, int>> nbr = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        DisjointSet dsu(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] == 0) continue;

                int key = i * m + j;

                for (auto &[r, c] : nbr) {

                    int new_x = i + r;
                    int new_y = j + c;

                    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || grid[new_x][new_y] == 0) continue;

                    int new_key = new_x * m + new_y;

                    dsu.union_by_size(key, new_key);
                }
            }
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    int key = i * m + j;
                    int parent = dsu.find_parent(key);
                    max_area = max(max_area, dsu.size[parent]);
                }
            }
        }
        return max_area;
    }
};