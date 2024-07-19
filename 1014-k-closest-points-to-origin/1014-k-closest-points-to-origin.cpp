class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using pp = pair<int,pair<int,int>>;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        int n = points.size();
        for(int i =0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist,{x,y}});
        }
        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            auto [d,p] = pq.top();
            pq.pop();
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};