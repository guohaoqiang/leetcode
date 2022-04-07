// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/discuss/1486511/Count-Transpose-and-Reverse

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        vector<vector<char>> tr(board[0].size(), vector<char>(board.size(),' '));
        
        for (size_t i=0; i<board.size(); ++i){
            for (size_t j=0; j<board[0].size(); ++j){
                tr[j][i] = board[i][j];
            }
        }
        
        return check(board, word) || check(board, string(word.rbegin(),word.rend())) ||
            check(tr, word) || check(tr, string(word.rbegin(),word.rend()));
    }
    
    bool check(vector<vector<char>>& b, string s){
        vector<vector<int>> h(b.size(),vector<int>(b[0].size(),-1));
        for (size_t i=0; i<b.size(); ++i){
            for (size_t j=0; j<b[0].size(); ++j){
                // potential start
                if (j==0 || b[i][j-1]=='#' || (j>0 && h[i][j-1]!=-1)){
                    int pos = 0;
                    if (j>0){
                        pos = h[i][j-1]+1;
                    }
                    if (s[pos]==b[i][j] || b[i][j]==' '){
                        
                        if (pos==s.size()-1){
                            // valid ending
                            if (j==b[0].size()-1 || b[i][j+1]=='#'){
                                return true;
                            }
                        }else{
                            h[i][j] = pos; 
                        }
                    }
                    
                }
            }
        }
        return false;
    }
};
