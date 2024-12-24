class Solution {
public:
    int a[4] = {1,0,-1,0};
    int b[4] = {0,1,0,-1};

    bool isSafe(int i, int j, vector<vector<int>> &grid){
        return i>=0 && j>=0 && i<grid.size() && j<grid.size();
    }

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxi = -1;
        vector<vector<int>> vis(n,vector<int> (n,0));
        queue<vector<int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    q.push({i,j,0});
                    vis[i][j] =1;
                }
            }
        }

        while(!q.empty()){
            vector<int> point = q.front();
            q.pop();

            int x = point[0];
            int y = point[1];
            int d = point[2];
            

            for(int i=0;i<4;i++){
                int x_ = x + a[i];
                int y_ = y + b[i];

                if(isSafe(x_,y_,grid) && !vis[x_][y_] && grid[x_][y_]==0) {
                    vis[x_][y_] =1;
                    maxi = max(maxi, d+1);                    
                    q.push({x_,y_,d+1});
                }
            }

        }
        return maxi;
    }
};