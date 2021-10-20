class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string s) {
        vector<int> dp(26,0);
        
        for (auto c:s){
            dp[c-'a'] = accumulate(dp.begin(),dp.end(),1l)%mod;
        }
        
        return accumulate(dp.begin(),dp.end(),0l)%mod;
    }
};
