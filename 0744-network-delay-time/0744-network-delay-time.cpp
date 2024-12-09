class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        
        using PI = pair<int,int>;
        priority_queue<PI,vector<PI>, greater<PI>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int dis = times[i][2];
            adj[u].push_back({v,dis});
        }
        
        pq.push({0,k});
        
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();

            for(auto adj:adj[node]){
                int nei = adj.first;
                int ew = adj.second;

                if(dis+ew <dist[nei]){
                    dist[nei] = dis+ew;
                    pq.push({dist[nei],nei});
                }
            }
        }
        int maxi = *max_element(dist.begin()+1,dist.end());
        return (maxi==INT_MAX)?-1:maxi;

    }
};