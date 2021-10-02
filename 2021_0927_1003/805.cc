class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        vector<int> dp(sum+1,0);
        dp.at(0) = 1;
        
        // the length of of subset 
        for (int i=1; i<nums.size(); ++i){
            
            for (int j=sum-nums.at(i); j>=0; --j){
                if (dp.at(j)){
                    // iterate over all the lengths
                    dp.at(j+nums.at(i)) |= (dp.at(j)<<1);
                }
            }
        }
        
        for (int k=1; k<nums.size(); ++k){
            if (k*sum%nums.size()==0){
                int s = k*sum/nums.size();
                // k: the length of the subset
                if (dp.at(s) && (dp.at(s) & (1<<k))){
                    return true;
                }
            }
        }
        
        return false;
    }
};
