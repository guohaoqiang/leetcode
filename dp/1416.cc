class Solution {
public:
    int mod = 1e9+7;
    int numberOfArrays(string s, int k) {
        // dp[i] denotes the counts of arrays ending with the i-th character
        vector<int> dp(s.size(),0);
        if (s[0]-'0'>=1 && s[0]-'0'<=k){
            dp[0] = 1;
        }
        for (int i=1; i<s.size(); ++i){
            int num = 0;
            for (int j=i; j>=max(0,i-8); --j){
                if (s[j]-'0'==0)  continue;
                
                num += (s[j]-'0')*pow(10,i-j); 
                
                if (num>k)  break;
                
                if (num>=1 && num<=k){
                    if (j==0)
                        dp[i] += 1; 
                    if (j>0 && i!=j)
                        dp[i] = (dp[i]+dp[j-1])%mod; 
                    if (j>0 && i==j)
                        dp[i] = dp[i-1];
                }
            }
        }
        return dp.back()%mod;
    }
};
