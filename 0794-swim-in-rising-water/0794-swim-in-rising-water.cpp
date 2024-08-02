class Solution {
public:
    int m,n;
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};

    bool isSafe(int i,int j){
        return (i>=0 && j>=0 && i<m && j<n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        using pi = pair<int,pair<int,int>>;

        vector<vector<bool>> vis (m,vector<bool>(n,0));

        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        int maxi = 0;

        while(!pq.empty()){
            auto [time,indexes] = pq.top();
            pq.pop();
            
            int i = indexes.first;
            int j = indexes.second;
            if(i== m-1 && j==n-1) return time;
            for(int k =0;k<4;k++){
                int i_ = i+ x[k];
                int j_ = j+ y[k];

                if(isSafe(i_,j_) && vis[i_][j_]==0){

                    pq.push({max(grid[i_][j_],time),{i_,j_}});
                    vis[i_][j_]=1;
                }
            }
        }
        return -1;
    }
};