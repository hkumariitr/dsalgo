class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]== -1) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        int maxi = INT_MIN;
        while(!q.empty()){
            auto [node,time] = q.front();
            q.pop();
            maxi = max(maxi,time);
            for(auto nei:adj[node]){
                q.push({nei,time+informTime[nei]});
            }
        }
        return maxi;
    }
};