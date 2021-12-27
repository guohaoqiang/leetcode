class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int r = m.size();
        for (int i=0; i<(r+1)/2; ++i){
            for (int j=0; j<r/2; ++j){
                int tmp = m[i][j];
                
                m[i][j] = m[r-1-j][i];
            
                m[r-1-j][i] = m[r-1-i][r-1-j];
            
                m[r-1-i][r-1-j] = m[j][r-1-i];
                
                m[j][r-1-i] = tmp;
            }
        }
    }
};
