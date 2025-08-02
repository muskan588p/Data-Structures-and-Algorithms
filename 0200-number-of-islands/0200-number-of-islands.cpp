class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
    int m = grid.size(), n = grid[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || vis[i][j])
        return;
    
    vis[i][j] = true;  // mark current cell as visited

    dfs(i + 1, j, grid, vis);
    dfs(i - 1, j, grid, vis);
    dfs(i, j + 1, grid, vis);
    dfs(i, j - 1, grid, vis);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    // if (m == 0 || n == 0 || grid == nullptr)
    if (m == 0 || n == 0 )
        return 0;

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int count = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1' && !vis[i][j]) {
                ++count;
                dfs(i, j, grid, vis);
            }
        }
    }
    return count;
}


};