class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<int> &vis,vector<int>& isSafe,int n){
        if(vis[n]==1) return;

        if(graph[n].size()==0){
            isSafe[n]=1;
            return;
        }

        vis[n]=1;
        bool safeFlag =1;

        for(auto nei:graph[n]){
            dfs(graph,vis,isSafe,nei);

            safeFlag = safeFlag && isSafe[nei];
        }

        isSafe[n] = safeFlag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> isSafe(n,0);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0) dfs(graph,vis,isSafe,i);
        }
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(isSafe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};