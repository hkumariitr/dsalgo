class Solution {
public:
    int m,n;
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};

    bool isSafe(int i,int j){
        return (i>=0 && j>=0 && i<m && j<n);
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        m = heightMap.size();
        n = heightMap[0].size();

        using pi = pair<int,pair<int,int>>;

        vector<vector<bool>> vis (m,vector<bool>(n,0));

        priority_queue<pi,vector<pi>,greater<pi>> pq;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    vis[i][j] =1;
                    pq.push({heightMap[i][j],{i,j}});
                }
            }
        }
        int water =0;
        while(!pq.empty()){
            auto [height,indexes] = pq.top();
            pq.pop();

            int i = indexes.first;
            int j = indexes.second;

            for(int k =0;k<4;k++){
                int i_ = i + x[k];
                int j_ = j + y[k];

                if(isSafe(i_,j_) && vis[i_][j_]==0){
                    if(heightMap[i_][j_]>=height){
                        pq.push({heightMap[i_][j_],{i_,j_}});
                        vis[i_][j_]=1;
                    }else{
                        water += height - heightMap[i_][j_];
                        pq.push({height,{i_,j_}});
                        vis[i_][j_]=1;
                    }
                }
            }
        }
        return water;
    }
};