class Solution {
public:
    void solveSudoku(vector<vector<char>>& b) {
        backtracking(b);
    }
    bool backtracking(vector<vector<char>>& b){
        for (int i=0; i<9; ++i){
            for (int j=0; j<9; ++j){
                if (b[i][j]!='.')   continue;
                
                for (int num=1; num<=9; ++num){
                    if (!check(b, i, j, num+'0')){
                        continue;
                    }
                
                    b[i][j] = num + '0';
                    if (backtracking(b)){
                        return true;
                    }
                    b[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    bool check(vector<vector<char>>& b, int r, int c, char ch){
        // column check
        for (int i=0; i<9; ++i){
            if (b[r][i]==ch)    return false;
        }
        // row check
        for (int i=0; i<9; ++i){
            if (b[i][c]==ch)    return false;
        }
        // 9X9 check
        int k1 = r/3;
        int k2 = c/3;
        for (int i=k1*3; i<k1*3+3; ++i){
            for (int j=k2*3; j<k2*3+3; ++j){
                if (b[i][j]==ch)    return false;
            }
        }
        return true;
    }
};
