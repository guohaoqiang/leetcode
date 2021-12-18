class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ans = 1;
        int idx = 0;
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (i==j){
                    dp[i][j] = true;
                }else if (i+1==j && s[i]==s[j]){
                    dp[i][j] = true;
                }
            }
        }
        
        for (int i=0; i<n; ++i){
            for (int j=0; j<i; ++j){
                if (j<i-1 && s[i]==s[j]){
                    dp[j][i] = dp[j+1][i-1];
                }
                if (dp[j][i] && ans<i-j+1){
                    ans = i-j+1;
                    idx = j;
                }
            }
        }
        return s.substr(idx,ans);
    }
};
