class neighborSum {
public:
    vector<vector<int>> ans;
    int m,n;
    unordered_map<int,pair<int,int>> mpp;
    bool isSafe(int i,int j){
        return i>=0 && j>=0 && i<m && j<n;
    }
    neighborSum(vector<vector<int>>& grid) {
        ans = grid;
        
        m = ans.size();
        n = ans[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mpp[ans[i][j]] = {i,j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int x[4] = {0,1,0,-1};
        int y[4] = {1,0,-1,0};
        int sum = 0;
        auto [i_,j_] = mpp[value];
        for(int k =0;k<4;k++){
            int i = i_ + x[k];
            int j = j_ + y[k];
            if(isSafe(i,j)){
                sum+=ans[i][j];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int x[4] = {-1,-1,1,1};
        int y[4] = {1,-1,-1,1};
        int sum = 0;
        auto [i_,j_] = mpp[value];
        
        for(int k =0;k<4;k++){
            int i = i_ + x[k];
            int j = j_ + y[k];
            
            if(isSafe(i,j)){
                sum+=ans[i][j];
            }
        }
        
        return sum;       
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */