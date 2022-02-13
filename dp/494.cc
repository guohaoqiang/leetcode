class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0.0);
        
        // positive sum: x
        // negative sum: y
        // x+y = sum
        // x-y = target
        // x = (sum+target)/2;
        
        if (abs(target)>sum || (sum+target)%2==1)   return 0;
        
        vector<int> dp(1001,0);
        dp[0] = 1;
        for (int i=0; i<nums.size(); ++i){
            for (int j=(sum+target)/2; j>=nums[i]; --j){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[(sum+target)/2];
    }
};
