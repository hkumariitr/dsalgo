class Solution {
public:
    int solve(int i,int j,string s,string t, vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!= -1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return dp[i][j]= solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve(i-1,j,s,t,dp);
        
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp (n+1,vector<long long> (m+1,0));
        for(int i =0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=m;j++){
                dp[i][j] = (s[i-1]==t[j-1]) ? (dp[i-1][j-1]+dp[i-1][j])%MOD :(dp[i-1][j])%MOD; 
            }
        }
        return dp[n][m];
        
    }
};