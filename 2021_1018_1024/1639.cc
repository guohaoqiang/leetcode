class Solution {
public:
    int mod = 1e9+7;
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int k = words[0].size();
        int len = target.size();
        vector<long> dp(len+1,0);
        dp[0] = 1;
        
        for (int i=0; i<k; ++i){
            vector<int> ct(26,0);
            for (int j=0; j<n; ++j){
                ct[words[j][i]-'a']++;
            }
            
            for (int p=len-1; p>=0; --p){
                dp[p+1] += dp[p]*ct[target[p]-'a']%mod;
            }
        }
        return dp.back()%mod;
    }
};
