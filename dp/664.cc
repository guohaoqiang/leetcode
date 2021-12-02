//https://leetcode.com/problems/strange-printer/discuss/1174488/Dp-Optimized-43ms
//https://leetcode.com/problems/strange-printer/discuss/152758/Clear-Logical-Thinking-with-Code
class Solution {
public:
    int strangePrinter(string s) {
        if (s.size()==0)    return 0;
        //remove consecutive duplicates
        string t = s.substr(0,1);
        char pre = s[0];
        for (int i=1; i<s.size(); ++i){
            if (pre != s[i]){
                pre = s[i];
                t += s[i];
            }
        }
        //initialization
        int n = t.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for (int i=0; i<n-1; ++i){
            dp[i][i] = 1;dp[i][i+1] = 2;
        }
        dp[n-1][n-1] = 1;
        
        //edge cases
        if (n==1)   return 1;
        if (n==2)   return 2;
        
        // bottom up dp
        for (int len=2; len<n; ++len){
            for (int j=0; j<n; ++j){
                if (j+len>=n)    break;
                dp[j][j+len] = min(dp[j][j+len-1],dp[j+1][j+len]) + (t[j]!=t[j+len]);
                
                for (int k=j; k<j+len; ++k){
                    int l = dp[j][k], r = dp[k+1][j+len];
                    if (j<k && t[j]==t[k]){
                        l = min(dp[j][k-1],dp[j+1][k]);
                    }
                    if (k+1<j+len && t[k+1]==t[j+len]){
                        r = min(dp[k+1][j+len-1],dp[k+2][j+len]);
                    }
                    
                    dp[j][j+len] = min(dp[j][j+len],l+r);
                }
            }
        }
        
        return dp[0][n-1];
    }
};

