class Solution {
public:
    vector<int> parent;
    vector<int> rnk;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rnk.resize(n + 1, 0);

        // Initialize each node as its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            // If both nodes share the same root, this edge creates a cycle
            if (find(edge[0]) == find(edge[1])) {
                return edge;
            }
            unite(edge[0], edge[1]);
        }

        return {};
    }

private:
    int find(int x) {
        // Path compression: point directly to root
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        // Union by rank: attach smaller tree under larger tree
        if (rnk[rootX] < rnk[rootY]) {
            parent[rootX] = rootY;
        } else if (rnk[rootX] > rnk[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rnk[rootX]++;
        }
    }
};