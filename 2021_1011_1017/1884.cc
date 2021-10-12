class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n+1,0);
        
        for (int i=1; i<=n; ++i){
            int tmp = INT_MAX;
            for (int j=1; j<=i; ++j){
                tmp = min(tmp, 1+max(dp[i-j], j-1));
            }
            dp[i] = tmp;
        }
        
        return dp.back();
    }
};
