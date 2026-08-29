class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        // Boundary checks and water check
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        // Mark current cell as visited
        grid[r][c] = 0;

        // Explore all 4 directions and count this cell (+1)
        return 1 + dfs(r + 1, c, grid) 
                 + dfs(r - 1, c, grid) 
                 + dfs(r, c + 1, grid) 
                 + dfs(r, c - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }

        return maxArea;
    }
};