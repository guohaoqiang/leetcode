class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int ans = INT_MIN;
        int i=0; 
        int j=nums.size()-1;
        while (i<j){
            if (nums[i]<k-nums[j]){
                ans = max(ans, nums[i++]+nums[j]);
            }else{
                j--;
            }
        }
        return ans==INT_MIN? -1 : ans;
    }
};
