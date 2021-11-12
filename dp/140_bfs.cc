class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> trace(s.size()+1,vector<int>());
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        unordered_set<string> mem(wordDict.begin(),wordDict.end());
        
        for (int i=1; i<=s.size(); ++i){
            for (int j=0; j<i; ++j){
                string str = s.substr(j,i-j);
                if (mem.count(str) && dp[j]){
                    dp[i] = true;
                    trace[i].push_back(j);
                }
            }
        }
        return bfs(trace, s.size(), s);
    }
    vector<string> bfs(vector<vector<int>>& t, int index, string s){
        if (index<=0)   return {""};
        vector<string> ans;
        for (int i=0; i<t[index].size(); ++i){
            string str = s.substr(t[index][i],index-t[index][i]);
            vector<string> sol = bfs(t, t[index][i], s);
            for (int j=0; j<sol.size(); ++j){
                if (sol[j]!=""){
                    sol[j] = sol[j] + " " + str;
                }else{
                    sol[j] = str;
                }
                ans.push_back(sol[j]);
            }
        }
        return ans;
    }
};
