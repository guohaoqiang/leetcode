class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for (auto digit:nums){
            sum += digit;
        }
        
        if ((sum+target)%2 || abs(target)>sum){
            return 0;
        }
        int tg = (sum+target)/2;
        
        vector<int> dp(1001,0);
        dp.at(0) = 1;
        
        for (int i=0; i<nums.size(); ++i){
            for (int j=tg; j>=nums.at(i); --j){
                dp.at(j) += dp.at(j-nums.at(i)); 
            }
        }
        
        return dp.at(tg);
    }
};
