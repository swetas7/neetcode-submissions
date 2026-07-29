class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>&order) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto neighbor : adj[node]) {
        // If neighbor hasn't been visited, traverse it
        if (!vis[neighbor]) {
            if (!dfs(neighbor, adj, vis, pathVis,order)) return false;
        } 
        // If neighbor is currently in the active DFS path, we found a cycle!
        else if (pathVis[neighbor]) {
            return false;
        }
    }

    pathVis[node] = 0; // Backtrack!
    order.push_back(node);
    return true;
}
   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int> pathVis(numCourses, 0);
        vector<int>order;
        for (int i = 0; i < numCourses; i++){
            if(vis[i]==0){
             // vector<int>pathvis(numCourses,0);
              if(!dfs(i,adj,vis,pathVis,order))return {};
            }
            }
            reverse(order.begin(),order.end());
            return order;
    }
};
