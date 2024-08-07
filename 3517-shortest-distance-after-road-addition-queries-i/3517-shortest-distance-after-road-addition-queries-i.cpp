class Solution {
public:
    int solve(vector<vector<int>> & adj,int n){
        vector<int> dist(n,1e9);
        dist[0]=0;
        using p = pair<int,int>;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            for(int nei:adj[node]){
                if(dis+1<dist[nei]){
                    dist[nei] = dis+1;
                    pq.push({dis+1,nei});
                }
            }
        }
        return dist[n-1];

    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj (n) ;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        int siz = queries.size();
        vector<int> ans;

        for(int i =0;i<siz;i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(solve(adj,n));
        }
        return ans;

    }
};