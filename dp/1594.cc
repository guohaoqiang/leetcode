class Solution {
public:
    int mod = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0]==0)   return 0;
        
        vector<vector<long long>> dp_min(m,vector<long long>(n));
        vector<vector<long long>> dp_max(m,vector<long long>(n));
        dp_min[0][0] = grid[0][0];
        dp_max[0][0] = grid[0][0];
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (i && j){
                    if (grid[i][j]<0){
                        dp_min[i][j] = max(dp_max[i][j-1],dp_max[i-1][j])*grid[i][j];
                        dp_max[i][j] = min(dp_min[i][j-1],dp_min[i-1][j])*grid[i][j];
                    }else {
                        dp_min[i][j] = min(dp_min[i][j-1],dp_min[i-1][j])*grid[i][j];
                        dp_max[i][j] = max(dp_max[i][j-1],dp_max[i-1][j])*grid[i][j];
                    }
                }
                if (i && !j){
                    dp_min[i][j] = dp_min[i-1][j]*grid[i][j];
                    dp_max[i][j] = dp_max[i-1][j]*grid[i][j];
                }
                if (!i && j){
                    dp_min[i][j] = dp_min[i][j-1]*grid[i][j];
                    dp_max[i][j] = dp_max[i][j-1]*grid[i][j];
                }
            }
        }
        int k = 0;
        return dp_max[m-1][n-1]>=0? dp_max[m-1][n-1]%mod : -1;
    }
};
