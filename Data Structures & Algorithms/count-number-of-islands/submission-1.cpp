class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int n) {

        rank.resize(n+1, 0);
        parent.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    bool union_by_rank(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return false;

        if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        }
        else {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size(), m = grid[0].size();
        
        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') islands++;
            }
        }

        vector<pair<int, int>> nbr = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        DisjointSet dsu(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] == '0') continue;

                int key = i * m + j;

                for (auto &[r, c] : nbr) {

                    int new_x = i + r;
                    int new_y = j + c;

                    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || grid[new_x][new_y] == '0') continue;

                    int new_key = new_x * m + new_y;

                    if (dsu.union_by_rank(key, new_key)) {
                        islands--;
                    }
                }
            }
        }
        return islands;
    }

private:
};
