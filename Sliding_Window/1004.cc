class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int len = nums.size();
        
        int i = 0;
        int ans = 0;
        for (int j=0; j<len; ++j){
            if (nums[j]==0){
                zero++;
            }
            while (zero>k && i<len){
                zero -= nums[i++]? 0 : 1;
            }
            ans = max(ans, j-i+1);
        }
        
        return ans;
    }
};
