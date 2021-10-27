//https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/discuss/780921/C%2B%2B-O(n)

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        // prefix_sum,left index
        unordered_map<int,int> dp;
        dp[0] = -1;
        int s = 0;
        // the right index of the last subarray
        int right = -1;
        int ans = 0;
        for (int i=0; i<nums.size(); ++i){
            s += nums[i];
            
            if(dp.count(s-target)){
                if (right<=dp[s-target]){
                    right = i;
                    ans++;
                }
            }
            dp[s] = i;
        }
        
        return ans;
    }
};
