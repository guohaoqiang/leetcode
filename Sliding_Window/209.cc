// https://leetcode.com/problems/minimum-size-subarray-sum/discuss/433123/JavaC%2B%2BPython-Sliding-Window

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        
        int i=0;
        int ans  = INT_MAX;
        for (int j=0; j<len; ++j){
            target -= nums[j];
            while (target<=0){
                ans = min(ans,j-i+1);
                target += nums[i++];
            }
        }
        return ans==INT_MAX? 0 : ans;
    }
};
