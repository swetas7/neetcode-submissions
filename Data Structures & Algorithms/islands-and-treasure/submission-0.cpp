class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) { int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>bfs;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)bfs.push({i,j});
            }
        }
        while(!bfs.empty()){
            int row[]={-1,0,1,0};
            int col[]={0,-1,0,1};
            auto it=bfs.front();
            int r=it.first;
            int c=it.second;
            bfs.pop();
            for(int i=0;i<4;i++){
               if((r+row[i])>=0&&(r+row[i])<n&&(c+col[i])>=0&&(c+col[i])<m&&grid[r+row[i]][c+col[i]]==2147483647){
                grid[r+row[i]][c+col[i]]=1+grid[r][c];
                bfs.push({r+row[i],c+col[i]});
               }
            }
        }

    }
};
