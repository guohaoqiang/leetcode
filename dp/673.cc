class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // the longest length ending with that letter
        vector<int> dp(nums.size(),1); 
        // the count corresponding to the ending letter
        vector<int> count(nums.size(),1);
        if (nums.size()==1) return 1;
        
        int max_len = 0;
        for (int i=1; i<nums.size(); ++i){
            for (int j=0; j<i; ++j){
                if (nums[i]>nums[j]){
                    if (dp[j]+1>dp[i]){
                        count[i] = count[j];
                        dp[i] = dp[j] + 1;
                    }else if (dp[j]+1==dp[i]){
                        count[i] += count[j];
                    }
                }
                max_len = max(max_len,dp[i]);
            }
        }
        int ans = 0;
        for (int i=0; i<nums.size(); ++i){
            if (dp[i]==max_len)
                ans += count[i];
        }
        return ans;
    }
};
