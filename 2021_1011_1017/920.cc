class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        long mod = 1e9+7;
        vector<vector<long>> dp(goal+1, vector<long>(n+1,0));
        dp[0][0] = 1;
        
        for (int i=1; i<=goal; ++i){
            for (int j=1; j<=n; ++j){
                // the last one is different from previous j-1 songs
                // dp(i,j): i songs of which j different songs
                dp[i][j] = dp[i-1][j-1]*(n-j+1)%mod;
                // the interval is k
                if (j>k){
                    dp[i][j] = (dp[i][j] + dp[i-1][j]*(j-k)%mod)%mod;
                }
            }
        }
        
        return dp.back().back();
    }
};
