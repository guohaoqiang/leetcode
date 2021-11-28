//https://leetcode.com/problems/student-attendance-record-ii/discuss/101643/Share-my-O(n)-C%2B%2B-DP-solution-with-thinking-process-and-explanation

class Solution {
public:
    int mod = 1e9+7;
    int checkRecord(int n) {
        //n*3 : (A,L,P)
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        if (n==1)    return dp[0][0] + dp[0][1] + dp[0][2];
        dp[1][0] = dp[0][1] + dp[0][2]; // 2
        dp[1][1] = dp[0][0] + dp[0][1] + dp[0][2];  // 3
        dp[1][2] = dp[0][0] + dp[0][1] + dp[0][2];  // 3
        
        if(n>2)    dp[2][0] = 4;
        
        for (int i=2; i<n; ++i){
            if (i>2){
                // [i][A]  = 
                dp[i][0] = ((dp[i-1][0] + dp[i-2][0])%mod + dp[i-3][0])%mod;
            }
            
            // [i][L]  = sub of [i-1][A]       +  sub of [i-1][P]
            dp[i][1] = ((dp[i-1][0] + dp[i-1][2])%mod + (dp[i-2][0] + dp[i-2][2])%mod)%mod;
            
            // P
            dp[i][2] = ((dp[i-1][0] + dp[i-1][1])%mod + dp[i-1][2])%mod;
        }
        
        return ((dp[n-1][0] + dp[n-1][1])%mod + dp[n-1][2])%mod; 
    }
};
