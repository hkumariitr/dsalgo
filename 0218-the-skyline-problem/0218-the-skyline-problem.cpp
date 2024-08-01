class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> points;
        int n = buildings.size();
        for(int i=0;i<n;i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            int ht = buildings[i][2];

            points.push_back({x,-ht});
            points.push_back({y,ht});
        }

        sort(points.begin(),points.end());
        vector<vector<int>> ans;
        multiset<int> pq;
        pq.insert(0);
        int cht = 0;
        n = points.size();
        for(int i =0;i<n;i++){
            auto[x,height] = points[i];
            if(height<0){
                pq.insert(-height);
            }else{
                auto it = pq.find(height);
                if (it != pq.end()) {
                    pq.erase(it);
                }
            }
            auto maxElement = *pq.rbegin();
            if(cht != maxElement){
                ans.push_back({x,maxElement});
                cht = maxElement;
            }
            
        }
        return ans;
        

    }
};