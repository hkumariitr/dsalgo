class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using pp = pair<int,pair<int,int>>;
        priority_queue<pp> pq;
        int n = points.size();
        int count =0;
        for(int i =0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist,{x,y}});
            count++;
            if(count>k){
                pq.pop();
                count--;
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [d,p] = pq.top();
            pq.pop();
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};