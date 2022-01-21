class Solution {
public:
    bool match(string& s, string& p, int i, int j, vector<vector<char>>& dp){
        if (j==p.size())    return i==s.size();
        
        if (dp[i][j]!=-1)   return dp[i][j];
        
        if (p[j]=='*'){
            return dp[i][j] = match(s, p, i, j+1, dp) || (i<s.size() && match(s, p, i+1, j, dp));
        }
        
        if (i<s.size() && (p[j]=='?' || s[i]==p[j])){
            return dp[i][j] = match(s, p, i+1, j+1, dp);
        }
        
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        vector<vector<char>> dp(s.size()+1, vector<char>(p.size(),-1));
        
        return match(s, p, 0, 0, dp);
    }
};
