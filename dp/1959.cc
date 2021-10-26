//https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/discuss/1390763/C%2B%2B-Bottom-Up-DP-Detailed-Explanation
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(),vector<int>(k+1,INT_MAX));
        int s = 0, mx = 0;
        for (int i=0; i<nums.size(); ++i){
            s += nums[i];
            mx = max(mx,nums[i]);
            dp[i][0] = mx*(i+1)-s;
        }
        for (int i=0; i<=k; ++i){
            dp[0][i] = 0;
        }
        for (int i=0; i<nums.size(); ++i){
            for (int m=1; m<=k; ++m){
                s = 0;
                mx = 0;
                for (int j=i; j>=0; --j){
                    s += nums[j];
                    mx = max(mx,nums[j]);
                    if (j==0){
                        dp[i][m] = min(mx*(i-j+1)-s,dp[i][m]);
                    }else {
                        // [0,i] =       ([0,j-1]+[j,i])         , [0,i]
                        dp[i][m] = min(dp[j-1][m-1]+mx*(i-j+1)-s,dp[i][m]);
                    }
                    
                }
            }
        }
        
        return dp[nums.size()-1][k];
    }
};
