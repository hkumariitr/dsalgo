class Solution {
public:
    int x[4]= {1,0,-1,0};
    int y[4]= {0,-1,0,1};

    bool isSafe(int i,int j , int r, int c){
        return i>=0 && j>=0 && i<r && j<c;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row,vector<int>(col,0));
        int fresh=0;
        queue<pair<int,int>> q;
        int time=0;
        int count =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) {
                    q.push({i,j}); 
                    count++;
                }
            }
        }

        if(fresh ==0) return 0;

        while(!q.empty()){
            int l=0;
            while(count--){
                auto[r,c] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x_ = r + x[i];
                    int y_ = c + y[i];

                    if(isSafe(x_,y_,row,col) && grid[x_][y_]==1 && visited[x_][y_]==0 ){
                        q.push({x_,y_});
                        fresh--;
                        visited[x_][y_]=1;
                        l++;
                    }
                }
            }
            cout<<"fresh reduced to "<<fresh<<endl;
            cout<<"inserted elements = "<<l<<endl;
            time++;
            count = l;
        }

        if(fresh>0) return -1;

        return time-1;

    }
};