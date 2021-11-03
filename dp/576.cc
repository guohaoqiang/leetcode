//https://leetcode.com/problems/out-of-boundary-paths/discuss/102966/C%2B%2B-6-lines-DP-O(N-*-m-*-n)-6-ms

class Solution {
public:
    int mod = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove==0) return 0;
        
        uint dp[51][50][50]={0};
        
        
        for (int i=1; i<=maxMove; ++i){
            for (int j=0; j<m; ++j){
                for (int k=0; k<n; ++k){
                    dp[i][j][k] = ((j==0? 1: dp[i-1][j-1][k]) + (j==m-1? 1: dp[i-1][j+1][k]) +
                        (k==0? 1: dp[i-1][j][k-1]) + (k==n-1? 1: dp[i-1][j][k+1]))%mod;
                }
            }
        }
        
        return dp[maxMove][startRow][startColumn];
    }
};
