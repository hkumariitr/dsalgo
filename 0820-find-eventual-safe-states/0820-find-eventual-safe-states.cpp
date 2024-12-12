class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto nei:graph[i]){
                adj[nei].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(int nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};