class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        vector<vector<int>> dp_acc(n,vector<int>(k+1,0));
        
        dp[0][0] = 1;
        dp_acc[0][0] = 1;
        for (int i=1; i<n; ++i){
            dp[i][0] = 1;
            dp_acc[i][0] += dp_acc[i-1][0] + dp[i][0];
        }
        int mod = 1e9+7;
        for (int i=1; i<n; ++i){
            for (int j=1; j<=k; ++j){
                dp[i][j] += (dp_acc[i-1][j-1] + dp[i-1][j]);
                dp[i][j] %= mod;
                
                dp_acc[i][j] += (dp_acc[i-1][j] + dp[i][j]);
                dp_acc[i][j] %= mod;
            }
        }
        
        return dp.back().back();
    }
};
