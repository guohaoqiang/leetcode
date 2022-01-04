class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        if (g[0][0] || g.back().back())    return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for (int i=1; i<m; ++i) {
            if (dp[i-1][0] && !g[i][0]){
                dp[i][0] = 1;
            }
        }
        for (int i=1; i<n; ++i){
            if (dp[0][i-1] && !g[0][i]){
                dp[0][i] = 1;
            }
        }
        
        for (int i=1; i<m; ++i){
            for (int j=1; j<n; ++j){
                if (!g[i][j]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp.back().back();
    }
};
