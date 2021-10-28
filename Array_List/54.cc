//https://leetcode.com/problems/spiral-matrix/discuss/20778/0ms-c%2B%2B-solution-take-turns-to-move-in-4-directions

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        int dir = 0;
        int ub = 0, lb = 0, rb = n-1, db = m-1;
        while (ub<=db && lb<=rb){
            ans.push_back(matrix[i][j]);
            switch (dir){
                case 0: 
                    if (j<rb){
                        j++;
                    }else {
                        dir = 1;
                        i++;ub++;
                    }
                    break;
                case 1:
                    if (i<db){
                        i++;
                    }else {
                        dir = 2;
                        rb--;j--;
                    }
                    break;
                case 2:
                    if (j>lb){
                        j--;
                    }else {
                        dir = 3;
                        i--;db--;
                    }
                    break;
                case 3:
                    if (i>ub){
                        i--;
                    }else {
                        dir = 0;
                        lb++;j++;
                    }
                    break;
            }
            
        }
        return ans;
    }
};
