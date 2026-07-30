class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int, int>>> adj(n + 1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto topp=pq.top();
            int time=topp.first;
            int node=topp.second;
            pq.pop();
            if(time>dist[node])continue;
            for(auto it:adj[node]){
                int wt=it.second;
                int nd=it.first;
                if((time+wt)<dist[nd]){
                    dist[nd]=dist[node]+wt;
                     pq.push({dist[nd],nd});
                }
               // pq.push((it.first,it.second));
            }
        }
        int mx=0;
        for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e9) return -1;
         mx=max(dist[i],mx);
        }
        return mx;
    }
};