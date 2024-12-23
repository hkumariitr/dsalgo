class Solution {
public:
    bool bfs(int newNode,vector<vector<int>> &adj, vector<int> color){
        queue<int> q;
        q.push(newNode);
        color[newNode]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for( auto nei :adj[node]){
                if(color[nei]!=-1 && color[nei]==color[node]){
                    return false;
                }else if(color[nei]==-1){
                    color[nei] = !color[node];
                    q.push(nei);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color (n+1,-1);
        vector<vector<int>> adj(n+1);
        for(auto i :dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(bfs(i,adj,color)==false) return false;
            }
        }
        return true;
    }
};