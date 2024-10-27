class Solution {
public:
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};

    bool isSafe(int i, int j, int row, int col){
        return i>=0 && j>=0 && i<row && j<col;
    }
    void dfs(int r, int c, vector<vector<char>>& grid,vector<vector<int>> &visited){
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int x_ = r + x[i];
            int y_ = c + y[i];

            if(isSafe(x_,y_,grid.size(),grid[0].size()) && grid[x_][y_]=='1' && visited[x_][y_]==0){
                dfs(x_,y_,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row,vector<int>(col,0));
        int count =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    cout<<"cnt increase for "<<i<<" "<<j<<endl;
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};