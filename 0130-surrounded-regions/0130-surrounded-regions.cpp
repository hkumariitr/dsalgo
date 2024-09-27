class Solution {
    int x[4]= {0,1,0,-1};
    int y[4]= {1,0,-1,0};
    int n,m;
public:
    bool isSafe(int i, int j){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(int i, int j, set<pair<int,int>> &vis,vector<vector<char>> board){
        vis.insert({i,j});
        for(int k=0;k<4;k++){
            int i_ = i+x[k];
            int j_ = j+y[k];
            if(isSafe(i_,j_) && board[i_][j_]=='O' && vis.find({i_, j_}) == vis.end()){
                dfs(i_,j_,vis,board);
            }
        };        
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        n = board.size();
        m = board[0].size();
        int row[] = {0,n-1};
        int col[] = {0,m-1};
        set<pair<int,int>> vis;

        for(int i:row){
            for(int j = 0;j<m;j++){
                if(board[i][j]=='O'){
                    dfs(i,j,vis,board);
                }
            }
        }
        
        for(int j:col){
            for(int i = 0;i<n;i++){
                if(board[i][j]=='O'){
                    dfs(i,j,vis,board);
                }
            }
        }
        bool l = vis.find({3,1})!= vis.end();
        cout<<l<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis.find({i,j})== vis.end()){
                    board[i][j] ='X';
                }
            }
        }
    }
};