class Solution {
public:
    int mod = 1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        vector<int> dp(2,0);
        for (int i=0; i<binary.size(); ++i){
            dp[binary[i]-'0'] = (dp[0] + dp[1] + binary[i]-'0')%mod;
        }
        return (dp[0]+dp[1]+(binary.find('0')!=string::npos))%mod;
        
    }
};
