class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // Step 1: Collect initial rotten fruits and count fresh ones
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // Edge case: no fresh fruits from the start
        if (fresh == 0) return 0;
        
        int minutes = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Step 2: Multi-source level-order BFS
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    // If adjacent cell is within bounds and fresh
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Mark as rotten
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        
        return fresh == 0 ? minutes : -1;
    }
};