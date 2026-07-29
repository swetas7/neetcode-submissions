class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Base case: out of bounds or water ('0')
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
            return;
        }

        // Mark current cell as visited by converting it to water
        grid[r][c] = '0';

        // Explore all 4 directions
        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    cnt++;          // 1. Found a new island!
                    dfs(grid, r, c); // 2. Mark the ENTIRE island as visited
                }
            }
        }

        return cnt;
    }
};