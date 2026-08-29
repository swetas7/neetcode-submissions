class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (int nbr : adj[node]) {
            if (nbr == parent) continue; // Skip edge leading back to parent
            if (vis[nbr]) return false;  // Cycle detected
            if (!dfs(nbr, node, adj, vis)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // Fast-fail: A valid tree with n nodes must have exactly n - 1 edges
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        // Check for cycles starting from node 0
        if (!dfs(0, -1, adj, vis)) return false;

        // Check for connectivity
        for (bool v : vis) {
            if (!v) return false;
        }

        return true;
    }
};