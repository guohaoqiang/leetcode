//https://leetcode.com/problems/concatenated-words/discuss/1602959/C%2B%2B-oror-DP-oror-Without-tle-oror-memoization
class Solution {
public:
    bool check(string& w, unordered_set<string>& st){
        int n = w.size();
        vector<int> dp(n+1,-1);
        
        st.erase(w);
        bool res = dfs(st, w, 0, dp);
        st.insert(w);
        return res;
    }
    bool dfs(unordered_set<string>& st, string& w, int start, vector<int>& dp){
        if (start==w.size())    return true;
        if (dp[start]!=-1)  return dp[start];
        
        string s = "";
        for (int i=start; i<w.size(); ++i){
            s += w[i];
            if (st.find(s)!=st.end() && dfs(st,w,i+1,dp)){
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        vector<string> ans;
        for (auto word:words){
            if (word.size()<=1) continue;
            
            if (check(word,st)){
                ans.push_back(word);
            }
            
        }
        return ans;
    }
};
