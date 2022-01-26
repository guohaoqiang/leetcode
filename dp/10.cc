class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return check(s, 0, p, 0, dp);
    }
    bool check(string& s, int i, string& p, int j, vector<vector<int>>& dp){
        if (j>=p.size()){
            return i==s.size();
        }
        if (dp[i][j]!=-1)   return dp[i][j];
        
        
        bool cur = (i<s.size() && (p[j]=='.' || s[i]==p[j]));
        int ans = -1;
        if (j+1<p.size() && p[j+1]=='*'){
            ans = check(s, i, p, j+2, dp) || (cur && check(s, i+1, p, j, dp));
        }else{
            ans = cur && check(s,i+1,p,j+1,dp);
        }
        
        return dp[i][j] = ans;
    }
};
