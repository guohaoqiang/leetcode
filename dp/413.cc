class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        
        for (int j=2; j<nums.size(); ++j){
            for (int i=j-2; i>=0; --i){
                if (nums[j]-nums[j-1]==nums[i+1]-nums[i]){
                    dp[j] += 1;
                }else{
                    break;
                } 
            }
        }
        return accumulate(dp.begin(),dp.end(),0);        
    }
};
