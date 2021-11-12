class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        unordered_set<string> mem(words.begin(),words.end());
        
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        
        for (int i=1; i<=s.size(); ++i){
            for (int j=0; j<i; ++j){
                string str = s.substr(j,i-j);
                if (mem.count(str) && dp[j]){
                    dp[i] = true;
                }
            }
        }
        return dp.back();  
    }
};
