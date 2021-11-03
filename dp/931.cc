class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int ans = INT_MAX;
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (i==0){
                    dp[i][j] = mat[i][j];
                    continue;
                }
                // i>0
                if (j==0){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]) + mat[i][j];
                    continue;
                }
                if (j==n-1){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + mat[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1])) + mat[i][j];
                
            }
        }
        for (int k=0; k<n; ++k)
            ans = min(ans,dp[n-1][k]);
        return ans;
    }
};
