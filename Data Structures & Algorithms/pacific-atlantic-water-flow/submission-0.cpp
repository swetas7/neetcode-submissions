class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& ocean, int prevHeight, vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Base cases: Out of bounds, already visited, or height is lower than previous cell
        if (r < 0 || r >= n || c < 0 || c >= m || ocean[r][c] == 1 || heights[r][c] < prevHeight) {
            return;
        }

        // Mark as reachable from this ocean
        ocean[r][c] = 1;

        // Traverse in all 4 directions
        dfs(r + 1, c, ocean, heights[r][c], heights); // Down
        dfs(r - 1, c, ocean, heights[r][c], heights); // Up
        dfs(r, c + 1, ocean, heights[r][c], heights); // Right
        dfs(r, c - 1, ocean, heights[r][c], heights); // Left
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
           dfs(0,i,pacific,INT_MIN,heights);
           dfs(n-1,i,atlantic,INT_MIN,heights);
          }
          for(int i=0;i<n;i++){
           dfs(i,0,pacific,INT_MIN,heights);
           dfs(i,m-1,atlantic,INT_MIN,heights);
          }
          vector<vector<int>>ans;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1&&atlantic[i][j]==1){
                 ans.push_back({i,j});
                }
            }
          
          }

          return ans;
        }
};