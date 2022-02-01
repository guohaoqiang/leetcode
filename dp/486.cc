class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        int first = helper(nums, 0, n-1, dp);
        int t = accumulate(nums.begin(), nums.end(), 0);
        
        return first>=t-first;
    }
    int helper(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if (i>j)    return 0;
        if (i==j) {
            return dp[i][j] = nums[i];
        }
        
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int take_i = nums[i] + min(
            helper(nums, i+2, j, dp),
            helper(nums, i+1, j-1, dp)
        );
        
        int take_j = nums[j] + min(
            helper(nums, i+1, j-1, dp),
            helper(nums, i, j-2, dp)
        );
        
        return dp[i][j] = max(take_i,take_j);
    }
};
