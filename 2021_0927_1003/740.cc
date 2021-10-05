class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> h(10001,0);
        
        for (int i=0; i<nums.size(); ++i){
            h.at(nums.at(i)) += nums.at(i);
        }
        
        vector<int> dp(10001,0);
        dp.at(1) = h.at(1);
        for (int i=2; i<h.size(); ++i){
            dp.at(i) = max(dp.at(i-1),dp.at(i-2)+h.at(i));
        }
        
        return dp.at(h.size()-1);
    }
};
