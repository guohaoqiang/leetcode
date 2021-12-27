class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int ans = 0;
        int prod = 1;
        for (int j=0; j<nums.size(); ++j){
            prod *= nums[j];
            if (prod<k){
                ans += (j-i+1);
            }else{
                while (i<=j && prod>=k){
                    prod /= nums[i++];
                }
                if (i<=j){
                    ans += (j-i+1);
                }
            }
        }
        
        return ans;
    }
};
