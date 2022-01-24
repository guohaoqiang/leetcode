class Solution {
public:
    vector<vector<string>> ans;
    vector<string> sol;
    vector<vector<string>> solveNQueens(int n) {
        backtracking(n,0);
        return ans;
    }
    void backtracking(int n, int r){
        if (sol.size()==n){
            ans.push_back(sol);
            return ;
        }
        for (int i=0; i<n; ++i){
            if (!check(r,i,n))    continue;
            
            sol.push_back(string(n,'.'));
            sol[r][i] = 'Q';
            backtracking(n,r+1);
            sol.pop_back();
        }
    }
    bool check(int r, int c, int n){
        // diagnol check
        for (int i=r-1,j=c-1; i>=0 && j>=0; --i,--j){
            if (sol[i][j]=='Q') return false;
        }
        // anti-diagnol check 
        for (int i=r-1,j=c+1; i>=0 && j<n; --i,++j){
            if (sol[i][j]=='Q') return false;
        }
        // vertical check
        for (int i=r-1; i>=0; --i){
            if (sol[i][c]=='Q') return false;
        }
        return true;
    }
};
