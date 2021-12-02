class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int,int> dp;
        
        int ans = 1;
        for (int i=0; i<n; ++i){
            dp[arr[i]] = dp[arr[i]-diff]+1;
            ans  = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
