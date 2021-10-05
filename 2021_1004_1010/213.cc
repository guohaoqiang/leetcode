class Solution {
public:
    
    int robrange(vector<int>& nums, int start, int end){
        vector<int> dp(end-start,0);
        
        if (end-start==1) return nums.at(start);
        if (end-start==2) return max(nums.at(start),nums.at(end-1));
        
        dp.at(0) = nums.at(start);
        dp.at(1) = max(nums.at(start),nums.at(start+1));
        for (int i=2; i<end-start; ++i){
            dp.at(i) = max(dp.at(i-2)+nums.at(start+i), dp.at(i-1));
        }
        
        return dp.back();
    }
    
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums.at(0);
        if (nums.size()==2) return max(nums.at(0),nums.at(1));
        // [ , )
        int head = robrange(nums, 0, nums.size()-1);
        int tail = robrange(nums, 1, nums.size());
        
        return max(head,tail);
    }
};
