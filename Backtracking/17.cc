class Solution {
public:
    vector<vector<char>> m = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string> ans;
    string sub;
    void backtracking(string s, int start){
        if (sub.size()==s.size()){
            ans.push_back(sub);
            return ;
        }
        
        for (int i=start; i<s.size(); ++i){
            int key = s[i]-'0'-2;
            for (int j=0; j<m[key].size(); ++j){
                sub += m[key][j];
                backtracking(s,i+1);
                sub.pop_back();
            }
        }
            
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        backtracking(digits,0);
        return ans;
    }
};
