class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2000,0));
        dp[0][0] = 1;
        int ans = 0;
        for (int i=1; i<n; ++i){
            for (int j=0; j<i; ++j){
                int dif = nums[i]-nums[j]+1000;
                if (dp[j][dif]) dp[i][dif] = (1+dp[j][dif]);
                else dp[i][dif] = 2;
                ans = max(ans,dp[i][dif]);
            }
        }
        
        return ans;
    }
};
