class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int k){
        if (k==word.size()) return true;
        
        if (i<0 || i>=m || j<0 || j>=n || word[k]!=board[i][j]) return false;
        
        board[i][j] = '*';
        bool ans = dfs(board, i, j+1, word, k+1) || 
            dfs(board, i+1, j, word, k+1) || 
            dfs(board, i-1, j, word, k+1) || 
            dfs(board, i, j-1, word, k+1);
        board[i][j] = word[k];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); n = board[0].size();
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (dfs(board,i,j,word,0))
                    return true;
                
            }
        }
        return false;
    }
};
