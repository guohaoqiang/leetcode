class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(10001,vector<int>(k+1,0));
        int m = 0;
        // m: #move
        // dp[m][k]: the #floors can be tested using m moves and k eggs
        while (dp[m][k]<n){
            m++;
            for (int j=1; j<=k; ++j){
                // the j-th drop + not break + break
                dp[m][j] = 1 + dp[m-1][j] + dp[m-1][j-1];
            }
        }
        return m;
    }
};
