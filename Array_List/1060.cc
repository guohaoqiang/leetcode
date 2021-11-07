class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        if (nums.size()==1) return nums[0]+k; 
        
        for (int i=1; i<nums.size(); ++i){
            if (nums[i]-nums[i-1]>k){
                return nums[i-1]+k;
            }
            k -= (nums[i]-nums[i-1]-1);
        }
        return nums.back()+k;
    }
};
