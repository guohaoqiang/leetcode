class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<int> row(b.size(),0);
        vector<int> col(9,0);
        vector<int> box(9,0);
        
        for (int i=0; i<b.size(); ++i){
            for (int j=0; j<b.size(); ++j){
                if (b[i][j]=='.')   continue;
                
                int pos = 1<<(( b[i][j]-'0' )-1);
                if (row[i] & pos){
                    return false;
                }
                row[i] |= pos;
                
                if (col[j] & pos){
                    return false;
                }
                col[j] |= pos;
                
                int idx = (i/3)*3+j/3;
                if (box[idx] & pos){
                    return false;
                }
                box[idx] |= pos;
            }
        }
        
        return true;
    }
};
