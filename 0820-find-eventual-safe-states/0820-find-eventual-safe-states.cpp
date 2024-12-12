class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathvis,
             vector<int>& safe, int node) {
        vis[node] = 1;
        pathvis[node] = 1;
        for (int nei : graph[node]) {
            if (vis[nei] == 0){
                if(dfs(graph, vis, pathvis, safe, nei)== true){
                    safe[node]=0;
                    return true;
                }
            }
            else if (pathvis[nei]){
                safe[node]=0;
                return true;
            }
        }
        safe[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> safe(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0)
                dfs(graph, vis, pathvis, safe, i);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};