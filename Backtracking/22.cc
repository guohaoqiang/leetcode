class Solution {
public:
    vector<string> ans;
    void backtracking(int n, int open, int close, string cur){
        if (cur.size()==2*n){
            ans.push_back(cur);
            return ;
        }
        
        if (open<n){
            backtracking(n,open+1,close,cur+"(");
        }
        if (close<open){
            backtracking(n,open,close+1,cur+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0, 0, "");
        return ans;
    }
};
