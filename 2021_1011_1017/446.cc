class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long,int>> dp(n);
        int ans = 0;
        for (int i=1; i<n; ++i){
            for (int j=0; j<i; ++j){
                long dif = (long)nums[i]-nums[j];
                int cnt = dp[j].count(dif)? dp[j][dif] : 0;
                
                dp[i][dif] += (cnt +1);
                ans += cnt;
            }
        }
        return ans;
    }
};
