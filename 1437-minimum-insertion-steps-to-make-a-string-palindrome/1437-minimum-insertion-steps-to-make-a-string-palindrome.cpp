class Solution {
public:
    int LCS(string p, string q, int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[i-1]==q[j-1]){
            return dp[i][j] = 1 + LCS(p,q,i-1,j-1,dp);
        }else{
            return dp[i][j] = max(LCS(p,q,i,j-1,dp),LCS(p,q,i-1,j,dp));
        }

    }
    int minInsertions(string s) {
        string str = s;
        cout<<str<<endl;
        reverse(str.begin(),str.end());
        cout<<str<<endl;
        int m= s.size();
        int n = str.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i =1;i<=m;i++){
            for(int j= 1;j<=n;j++){
                dp[i][j] = (s[i-1]==str[j-1]) ?  1 + dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return s.size()-dp[m][n];
    }
};