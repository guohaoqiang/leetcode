// https://leetcode.com/problems/rank-transform-of-a-matrix/discuss/909212/C%2B%2B-with-picture

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> rows(m,0), cols(n,0);
        vector<vector<int>> arr;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                arr.push_back({mat[i][j], i, j});
            }
        }
        sort(arr.begin(), arr.end());
        int last_v = INT_MIN;
        vector<vector<int>> cur;
        for (auto it:arr){
            if (it[0]!=last_v){
                process(mat, cur, rows, cols);
                last_v = it[0];
                cur.clear();
            }
            cur.push_back(it);
        }
        process(mat, cur, rows, cols);
        
        return mat;
    }
    void process(vector<vector<int>>& mat, vector<vector<int>>& cur, vector<int>& rows, vector<int>& cols){
        vector<int> f(mat.size()+mat[0].size(), -1);
        
        for (auto it:cur){
            int fi = find(f, it[1]), fj = find(f, rows.size()+it[2]);
            if (fi!=fj){
                f[fi] = min(min(f[fi], f[fj]), -max(rows[it[1]], cols[it[2]])-1);
                f[fj] = fi;
            }
        }
        
        for (auto it:cur){
            mat[it[1]][it[2]] = rows[it[1]] = cols[it[2]] = -f[find(f,it[1])];
        }
    }
    int find(vector<int>& f, int i){
        return f[i]<0? i : f[i]=find(f, f[i]);
    }
};
