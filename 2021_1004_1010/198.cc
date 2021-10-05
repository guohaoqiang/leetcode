class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums.at(0);
        }
        
        if (nums.size()==2){
            return max(nums.at(0),nums.at(1));
        }
        
        vector<int> dp(nums.size(), 0);
        dp.at(0) = nums.at(0);
        dp.at(1) = max(nums.at(0),nums.at(1));
        
        for (int i=2; i<nums.size(); ++i){
            dp.at(i) = max(dp.at(i-1),dp.at(i-2)+nums.at(i));
        }
        
        return dp.back();
    }
};
