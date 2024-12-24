class Solution {
public:
    vector<int> dijsktra(int start,vector<vector<pair<int,int>>> &adj ){
        int n = adj.size();
        vector<int> dist(n,INT_MAX);
        dist[start] =0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,start});
        
        while(!pq.empty()){
            auto pair = pq.top();
            int node = pair.second;
            int dis = pair.first;
            pq.pop();

            for(auto nei:adj[node]){
                int node2 = nei.first;
                int edw = nei.second;
                
                if(dist[node2]>dis + edw){
                    // cout<<"called"<<endl;
                    dist[node2] = dis + edw;
                    pq.push({dis+edw,node2});
                }
            }

        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge :edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<vector<int>> distances(n);
        for(int i=0;i<n;i++){
            distances[i] = dijsktra(i,adj);
        }
        int mini = INT_MAX;
        int ans =0;
        for(int i = 0;i<n;i++){
            int cnt =0;
            cout<<"from city "<<i<<endl;
            vector<int> citiesd = distances[i];
            for(int j=0;j<n;j++){
                cout<<"to city "<<j<<" distance = "<<citiesd[j]<<endl;
                if(citiesd[j]<=distanceThreshold) cnt++;
            }
            if(cnt-1<=mini) {
                mini = cnt-1;
                ans = i;
            }
        }
        return ans;
    }
};