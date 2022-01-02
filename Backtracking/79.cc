class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    int m,n;
    bool backtracking(vector<vector<char>>& b, string s, int i, int j, int idx){
        if (idx==s.size()){
            return true;
        }
        
        for (int k=0; k<4; ++k){
            int x = i+dir[k];
            int y = j+dir[k+1];
            if (x<0 || x>=m || y<0 || y>=n || b[x][y]=='*' || b[x][y]!=s[idx]){
                continue;
            }
            b[x][y] = '*';
            if (backtracking(b, s, x, y, idx+1)){
                return true;
            }
            b[x][y] = s[idx];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (board[i][j]!=word[0])   continue;
                board[i][j] = '*';
                if (backtracking(board, word, i, j, 1)){
                    return true;
                }
                board[i][j] = word[0];
            }
        }
        return false;
    }
};
